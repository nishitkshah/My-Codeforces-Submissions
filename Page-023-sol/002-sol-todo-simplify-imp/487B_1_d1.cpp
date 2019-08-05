//23:14 02-07-2019 to 23:21 02-07-2019
//23:38 03-07-2019
//00:18 04-07-2019

#include<bits/stdc++.h>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100010
#define INF 1000000010LL

int n, s, l, a[N_], li, ri, lv[N_], rv[N_];
long long dp[N_];
deque< pair<int, int> > mn, mx;
deque< pair<long long, int> > mna;

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> s >> l;
RE(i, 0, n) cin >> a[i];
if(l>n){
	cout << "-1\n";
	//RE(i, 0, n) cerr << lv[i] << ' ' << rv[i] << '\n';
	return 0;
}
lv[0] = rv[0] = 0;
li = ri = 0;
mn.push_back({a[0], 0});
mx.push_back({a[0], 0});
RE(i, 1, n){
	ri = i;
	while(!mn.empty() && mn.back().first>=a[i])
		mn.pop_back();
	mn.push_back({a[i], i});
	while(!mx.empty() && mx.back().first<=a[i])
		mx.pop_back();
	mx.push_back({a[i], i});
	while((mx.front().first-mn.front().first)>s){
		li++;
		if(mn.front().second<li) mn.pop_front();
		if(mx.front().second<li) mx.pop_front();
	}
	lv[i] = li;
	rv[i] = ri;
}
li = -1;
ri = -1;
mna.push_back({0, -1});
RE(i, 0, l-1) dp[i] = INF;
RE(i, l-1, n){
	ri = i-l;
	if(li<(lv[i]-1)) li = lv[i]-1;
	while(!mna.empty() && mna.front().second<li) mna.pop_front();
	if(!mna.empty())
		dp[i] = mna.front().first+1;
	else
		dp[i] = INF;
	while(!mna.empty() && mna.back().first>=dp[ri+1]) mna.pop_back();
	mna.push_back({dp[ri+1], ri+1});
}
if(dp[n-1]<INF)
	cout << dp[n-1] << '\n';
else
	cout << "-1\n";
}

//00:16 04-07-2019
//01:05 04-07-2019
//01:07 04-07-2019
