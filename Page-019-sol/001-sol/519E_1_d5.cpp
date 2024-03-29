//20:52 28-01-2019 - read editorial
//21:28 28-01-2019
//22:08 28-01-2019
//22:16 28-01-2019
//22:26 28-01-2019
//22:54 28-01-2019 - used gdb
//23:47 28-01-2019

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100001
#define LgN 18

int n, m, lgn, par[N_][LgN], dpt[N_], u, v, cnt[N_]={0};
vector<int> t[N_];

int dfs(int nd, int pt, int dh){
dpt[nd] = dh;
par[nd][0] = pt;
cnt[nd] = 1;
int i=0, cpt=pt;
if(cpt!=-1)
	while(par[cpt][i]!=-1){
		cpt = par[nd][i+1] = par[cpt][i];
		i++;
	}
for(auto nc: t[nd])
	if(nc!=pt)
		cnt[nd] += dfs(nc, nd, dh+1);
return cnt[nd];
}

int moveup_d(int nd, int d){
int dh = dpt[nd] - d;
if(dh<0) dh = 0;
int p=lgn-1;
while(dpt[nd]!=dh){
	if(par[nd][p]!=-1 && dpt[par[nd][p]]>=dh)
		nd = par[nd][p];
	p--;
}
return nd;
}

int lca(int x, int y){
if(dpt[y]>dpt[x]) swap(x, y);
x = moveup_d(x, dpt[x]-dpt[y]);
if(x==y) return x;
int p = lgn-1;
while(par[x][0]!=par[y][0]){
	if(par[x][p]!=par[y][p]){
		x = par[x][p];
		y = par[y][p];
	}
	p--;
}
return par[x][0];
}

void init(){
lgn = 1;
while(n>(1<<lgn)) lgn++;
//cerr << "Dbg lgn " << lgn << '\n';
RE(i, 1, n+1)
	RE(j, 0, lgn) par[i][j] = -1;
}

int dist(int x, int y){
	//cerr << "Err: " << lca(x, y) << endl;
	//cerr << "Err: d " << dpt[lca(x, y)] << '\n';
	return dpt[x]+dpt[y]-2*dpt[lca(x, y)];
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n;
RE(i, 0, n-1){
	cin >> u >> v;
	t[u].push_back(v);
	t[v].push_back(u);
}
init();
dfs(1, -1, 0);
cin >> m;
RE(i, 0, m){
	cin >> u >> v;
	int ans, d=dist(u, v);
	//cerr << "Dbggg lca dis " << lca(u, v) << ' ' << dist(u, v) << '\n';
	if(u==v)
		ans = n;
	else if(d%2)
		ans = 0;
	else if(dpt[u]==dpt[v]){
		u = moveup_d(u, d/2-1);
		v = moveup_d(v, d/2-1);
		ans = n-cnt[u]-cnt[v];
	}else{
		if(dpt[v]>dpt[u]) swap(u, v);
		int p, pc;
		pc = moveup_d(u, d/2-1);
		p = par[pc][0];
		ans = cnt[p]-cnt[pc];
	}
	cout << ans << '\n';
}
}

//22:06 28-01-2019
//22:09 28-01-2019
//22:17 28-01-2019
//22:52 28-01-2019
//23:45 28-01-2019
//23:49 28-01-2019
//23:49 28-01-2019
