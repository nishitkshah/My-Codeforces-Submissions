//23:14 02-07-2019 to 23:21 02-07-2019
//23:38 03-07-2019

#include<bits/stdc++.h>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100010

int n, s, l, a[N_], li, ri, lv[N_], rv[N_], dp[N_];
deque< pair<int, int> > mn, mx;
bool imposs = false;

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> s >> l;
RE(i, 0, n) cin >> a[i];
if(l>n) imposs = true;
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
		if(mn.front().second<l) mn.pop_front();
		if(mx.front().second<l) mx.pop_front();
	}
	lv[i] = li;
	rv[i] = ri;
	if((ri-li+1)<l){
		imposs = true;
		break;
	}
}
if(imposs){
	cout << "-1\n";
	return 0;
}
mn.clear();
li = 0;
ri = 0;
RE(i, 0, l-1) dp[i] = 0;
dp[l-1] = 1;
mn.push_back({dp[0], 0});
RE(i, l, n){
	ri = i-l;
	if(li<lv[i]) li = lv[i];
	while(mn.front().second<li) mn.pop_front();
	dp[i] = mn.front().first+1;
	while(!mn.empty() && mn.back().first>=dp[ri]) mn.pop_back();
	mn.push_back({dp[ri], ri});
}
cout << dp[n-1] << '\n';
}

//00:16 04-07-2019
