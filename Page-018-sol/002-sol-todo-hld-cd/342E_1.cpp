//15:06 15-01-2019 to 15:32 15-01-2019 - read editorial
//16:17 15-01-2019 to 16:24 15-01-2019 and 18:49 15-01-2019

#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define SI(a) scanf("%d", &(a))
#define N_ 100000

int n, m, sqm, x, y;
int t[N_], v[N_], c[N_]={0}, d[N_], dpt[N_], pw[N_+1], pp[N_+1], vis[N_];
vector<int> g[N_], rd, lca[N_];
queue< pair<int, int> > q;

inline void input(){
SI(n); SI(m);
RE(i, 0, n-1){
	SI(x); SI(y);
	x--; y--;
	g[x].push_back(y); g[y].push_back(x);
}
RE(i, 0, m){
	SI(t[i]); SI(v[i]);
	v[i]--;
}
}

void dfs(int nd=0, int dh=0, int p=-1){	//Initialize lca, dpt and d (least dist from red node)
d[nd] = dpt[nd] = dh;

if(p>=0) lca[nd].push_back(p);
int ind=0, pt=p;
while(pt>=0 && lca[pt].size()>ind){
	pt = lca[pt][ind];
	ind++;
	lca[nd].push_back(pt);
}

for(auto nn: g[nd])
	if(nn!=p)
		dfs(nn, dh+1, nd);
}

inline void init(){
sqm = (int)sqrt((float)m);
c[0] = 1;
rd.push_back(0);
dfs(0, 0);
pw[0] = 0; pw[1] = 1;
pp[0] = -1; pp[1] = 0;
RE(i, 2, n+1){
	pw[i] = pw[i-1], pp[i] = pp[i-1];
	if(2*pw[i-1]==i) pw[i] = i, pp[i]++;
}
}

int lca(int x, int y){
if(dpt[x]>dpt[y]) swap(x, y);
if(dpt[x]!=dpt[y]){
	int dx = dpt[y]-dpt[x];
	int npw = pw[dx];
	while(dx){
		y = lca[y][pp[npw]];
		dx -= npw;
		npw = pw[dx];
	}
}
//x and y are in same level now
if(x==y) return x;
int lv=min(lca[x].size(), lca[y].size())-1;
while(lca[x][0]!=lca[y][0]){
	lv=min(lv, min(lca[x].size()-1, lca[y].size()-1));
	while(lca[x][lv]==lca[y][lv]) lv--;
	x = lcx[x][lv], y = lca[y][lv];
}
return lca[x][0];
}

void bfs(){
for(auto r: rd){
	q.push_back({r, 0});
	vis[r] = 1;
}
while(q.size()){
	auto pii = q.top();
	q.pop();
	int nd=pii.first, dh=pii.second;
	d[nd] = dh;
	for(auto nn: g[nd]){
		if(!vis[nn]){
			vis[nn] = 1;
			q.push_back({nn, dh+1});
		}
	}
}
RE(i, 0, n) vis[i] = 0;	//reset visited array for next run
}

main(){
input();
init();
for(int i=0; i<m; i+=sqm){
	bfs();
	int rdsz = rd.size();
	RE(j, i, i+sqm){
		if(t[i]==1){
			cl[v[i]] = 1;
			rd.push_back(v[i]);
		}else{
			int ans = d[v[i]];
			for(ri, rdsz, rd.size()){
				int rt = lca(v[i], rd[ri]);
				ans = min(ans, dpt[v[i]]+dpt[rd[ri]]-2*dpt[rt]);
			}
			printf("%d\n", ans);
		}
	}
}
}

//20:02 15-01-2019
