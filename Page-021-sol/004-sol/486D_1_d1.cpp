//18:17 10-03-2019
//18:56 10-03-2019
//19:10 10-03-2019

#include<iostream>
#include<vector>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 2001
#define MOD 1000000007

int d, n, a[N_];
vector<int> t[N_];
long long ans=0LL;

input(){
cin >> d >> n;
RE(i, 1, n+1) cin >> a[i];
int u, v;
RE(i, 1, n){
	cin >> u >> v;
	t[u].push_back(v);
	t[v].push_back(u);
}
}

long long dfs(int nd, int mx, int pt){
long long ret = 1LL;
for(auto nc: t[nd]){
	if(nc!=pt && (mx-d)<=a[nc] && a[nc]<=mx){
		ret *= dfs(nc, mx, nd) + 1LL;
		ret %= MOD;
	}
}
return ret;
}

main(){
input();
RE(i, 1, n+1){
	ans += dfs(i, a[i], 0);
	ans %= MOD;
}
cout << ans << '\n';
}

//19:09 10-03-2019
//19:10 10-03-2019
