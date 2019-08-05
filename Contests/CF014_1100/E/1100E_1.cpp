//20:59 13-01-2019 - used template
//21:10 13-01-2019

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100001

struct edge{
int u, v, c, i, inc;
};

int n, m, dpt[N_]={0}, r[N_], cc[N_]={0};
vector<edge> e;
vector<int> g[N_];

bool cmp_c(const edge &a, const edge &b){
if(a.c!=b.c) return a.c>b.c;	//Note: greater than
if(a.u!=b.u) return a.u<b.u;
if(a.v!=b.v) return a.v<b.v;
return a.i<b.i;
}

bool cmp_i(const edge &a, const edge &b){
return a.i<b.i;
}

int root(int x){
	int c=x, rt=x;
	while(r[rt]>=0) rt = r[rt];
	while(x!=rt){
		c = r[x];
		r[x] = rt;
		x = c;
	}
	return rt;
}

bool merge(int x, int y){
int rx=root(x), ry=root(y);
if(rx==ry) return false;
if(r[rx]>r[ry]) swap(rx, ry);
r[rx] += r[ry];
r[ry] = rx;
return true;
}

void init(){
cin >> n >> m;
RE(i, 0, n) r[i] = -1;
e.resize(m);
RE(i, 0, m){
	int u, v, c;
	cin >> u >> v >> c;
	u--; v--;
	e[i].u = u;
	e[i].v = v;
	e[i].c = c;
	e[i].i = i;
	e[i].inc = 0;
}
sort(e.begin(), e.end(), cmp_c);
}

void dfs(int nd, int d=1){
dpt[nd] = max(dpt[nd], d);
for(auto nn: g[nd])
	dfs(nn, d+1);
}

main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
init();
RE(i, 0, m){
	if(root(e[i].u) != root(e[i].v)){
		e[i].inc = 1;
		merge(e[i].u, e[i].v);
		cc[e[i].v]++;
		g[e[i].u].push_back(e[i].v);
	}
}
RE(i, 0, n)
	if(cc[i]==0)
		dfs(i);
sort(e.begin(), e.end(), cmp_i);
int mxc = 0;
vector<edge> ans_e;
for(auto ed: e){
	if(ed.inc==0 && dpt[ed.u]>dpt[ed.v]){
		//Solution won't work as we can't determine whether u can be reached from v in the tree
		//Still trying
		ans_e.push_back(ed);
		mxc = max(mxc, ed.c);
	}
}
cout << mxc << ' ' << ans_e.size() << '\n';
for(auto ed: ans_e)
	cout << ed.i+1 << ' ';
cout << '\n';
}

//21:57 13-01-2019
//21:58 13-01-2019
