//01:51 04-01-2019 to 01:57 04-01-2019 and 09:38 13-01-2019 to 09:40 13-01-2019 - read editorial
//09:40 13-01-2019

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100000

int n, a, b;
long long v[N_], dpp[N_], dpm[N_];
vector<int> t[N_];


void dfs(int r, int p){
dpp[r] = 0, dpm[r] = 0;
for(auto c: t[r]){
	if(c==p) continue;
	dfs(c, r);
	dpp[r] = max(dpp[c], dpp[r]);
	dpm[r] = max(dpm[c], dpm[r]);
}
v[r] += dpp[r]-dpm[r];
if(v[r]>0) dpm[r] += v[r];
else dpp[r] += (-v[r]);
}


main(){
cin >> n;
RE(i, 0, n-1){
	cin >> a >> b;
	a--, b--;
	t[a].push_back(b);
	t[b].push_back(a);
}
RE(i, 0, n) cin >> v[i];
dfs(0, 0);
cout << dpp[0]+dpm[0] << '\n';
}

//09:56 13-01-2019
//10:02 13-01-2019
