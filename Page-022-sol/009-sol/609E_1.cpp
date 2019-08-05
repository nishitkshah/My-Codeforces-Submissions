//22:15 11-06-2019 to 22:40 11-06-2019
//07:34 12-06-2019 to 07:54 12-06-2019 and 22:06 13-06-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ (2001*100)
#define Lg 20

int n, m, u[N_], v[N_], wt[N_], r[N_], lca[N_][Lg]={0}, wmx[N_][Lg]={0}, dpt[N_]={0};
vector<int> g[N_], w[N_], mst[N_], tw[N_];
vector< pair< int, pair<int, int> > > e;

inline int root(int x){
if(r[x]<0) return x;
return r[x] = root(r[x]);
}

bool merge(int x, int y){
x = root(x);
y = root(y);
if(x==y) return false;
if(r[x]>r[y]) swap(x, y);
r[x] += r[y];
r[y] = x;
return true;
}

int dfs(int nd, int pr=0, int wt=0, int dpth=1){
dpt[nd] = dpth;
lca[nd][0] = pr;
wmx[nd][0] = wt;
RE(i, 1, Lg){
	if(lca[nd][i-1]){
		lca[nd][i] = lca[lca[nd][i-1]][i-1];
		wmx[nd][i] = max(wmx[nd][i-1], wmx[lca[nd][i-1]][i-1]);
	}
}
RE(i, 0, mst[nd].size())
	if(mst[nd][i]!=pr)
		dfs(mst[nd][i], nd, tw[nd][i], dpth+1);
}

int get_mxwt(int x, int y){
int mxwt=0;
if(dpt[x]<dpt[y]) swap(x, y);
int d = dpt[x]-dpt[y];
for(int i=Lg-1; d>0; i--){
	if((1<<i)>d) continue;
	d -= 1<<i;
	mxwt = max(mxwt, wmx[x][i]);
	x = lca[x][i];
}
if(x==y) return mxwt;
int b=Lg-1;
while(lca[x][0]!=lca[y][0]){
	while(lca[x][b]==lca[y][b])
		b--;
	mxwt = max(mxwt, wmx[x][b]);
	mxwt = max(mxwt, wmx[y][b]);
	x = lca[x][b]; y = lca[y][b];
}
mxwt = max(mxwt, wmx[x][0]);
mxwt = max(mxwt, wmx[y][0]);
return mxwt;
}

main(){
cin >> n >> m;
RE(i, 1, n+1) r[i] = -1;
RE(i, 0, m){
	cin >> u[i] >> v[i] >> wt[i];
	g[u[i]].push_back(v[i]); g[v[i]].push_back(u[i]);
	w[u[i]].push_back(wt[i]); w[v[i]].push_back(wt[i]);
	e.push_back({wt[i], {u[i], v[i]}});
}
sort(e.begin(), e.end());
long long mstw = 0LL;
for(auto piii: e){
	int cw=piii.first, cu=piii.second.first, cv=piii.second.second;
	if(merge(cu, cv)){
		mst[cu].push_back(cv); mst[cv].push_back(cu);
		tw[cu].push_back(cw); tw[cv].push_back(cw);
		mstw += cw;
	}
}
dfs(1, 0);
RE(i, 0, m)
	cout << mstw - get_mxwt(u[i], v[i]) + wt[i] << '\n';
}

//22:36 13-06-2019
//22:37 13-06-2019
