//23:05 04-05-2019
//23:22 04-05-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100100
#define INF 10001000
int n, k, x[N_], l[N_], h[N_];
vector< pair<int, int> > v;

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
RE(i, 0, N_) l[i]=INF, h[i]=0;
cin >> n >> k;
RE(i, 1, n+1){
	cin >> x[i];
	l[x[i]] = min(l[x[i]], i);
	h[x[i]] = max(h[x[i]], i);
}
RE(i, 1, n+1){
	if(i-1)
		v.push_back({i, i-1});
	v.push_back({i, i});
	if((i+1)<=n)
		v.push_back({i, i+1});
}
int ans = 0;
for(auto pii: v){
	int f=pii.first, s=pii.second;
	if(h[s]<l[f]) ans++;
}
cout << ans << '\n';
}

//23:30 04-05-2019
