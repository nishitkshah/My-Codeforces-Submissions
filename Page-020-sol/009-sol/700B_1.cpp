//10:50 24-02-2019 to 11:11 24-02-2019 - read editorial
//07:48 25-02-2019

#include<iostream>
#include<vector>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 200001

int n, k, u[N_], c[N_]={0};
vector<int> t[N_];
long long ans = 0LL;

int dfs(int nd, int p){
int sm = c[nd];
for(auto nc: t[nd])
	if(nc!=p)
		sm += dfs(nc, nd);
ans += min(sm, 2*k-sm);
return sm;
}

main(){
cin >> n >> k;
RE(i, 0, 2*k){
	cin >> u[i];
	c[u[i]] = 1;
}
RE(i, 0, n-1){
	int x, y;
	cin >> x >> y;
	t[x].push_back(y);
	t[y].push_back(x);
}
dfs(1, 0);
cout << ans << '\n';
}

//08:01 25-02-2019
//08:04 25-02-2019
