//23:12 21-07-2019 to 23:32 21-07-2019
//23:01 22-07-2019
//23:23 22-07-2019
//23:27 22-07-2019

#include<bits/stdc++.h>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define P_ 1000100
#define MD (1000*1000*1000 + 7)

long long p, k, vis[P_];
vector<int> g[P_];

void dfs(int nd){
vis[nd] = 1;
for(auto nc: g[nd])
	if(!vis[nc])
		dfs(nc);
}

long long pw(long long a, int p, long long M=MD){
long long r=1LL;
while(p){
	if(p%2) r = (a*r)%M;
	a = (a*a)%M;
	p >>= 1;
}
return r;
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> p >> k;
if(k<2){
	if(k==0) cout << pw(p, p-1) << '\n';
	else if(k==1) cout << pw(p, p) << '\n';
	return 0;
}
vis[0] = 1;
RE(i, 1, p){
	int j = (int)((k*i)%p);
	g[i].push_back(j);
	g[j].push_back(i);
}
int cnt = 0;
RE(i, 1, p)
	if(!vis[i]){
		cnt++;
		dfs(i);
	}
cout << pw(p, cnt) << '\n';
}

//23:16 22-07-2019
//23:24 22-07-2019
//23:29 22-07-2019
//23:30 22-07-2019
