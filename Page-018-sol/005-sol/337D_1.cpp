//07:59 21-01-2019 - read problem and editorial before
//08:03 21-01-2019

#include<iostream>
#include<vector>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100001

int n, m, d, p[N_], c[N_]={0}, pr[N_], mx[N_][2], ind[N_][2];
vector<int> t[N_];

void add_mx(int nd, int mxv, int indv){
	if(mxv==0) return;
	if(mxv > mx[nd][0]){
		mx[nd][1] = mx[nd][0];
		ind[nd][1] = ind[nd][0];
		mx[nd][0] = mxv;
		ind[nd][0] = indv;
		return;
	}
	if(mxv > mx[nd][1]){
		mx[nd][1] = mxv;
		ind[nd][1] = indv;
	}
}

void dfs(int nd, int prt){
pr[nd] = prt;
if(c[nd]){
	mx[nd][0] = 0;
	ind[nd][0] = nd;
}
for(auto nc: t[nd]){
	if(nc!=prt)
		dfs(nc, nd);
	add_mx(nd, mx[nc][0]+1, nc);
}
}

void dfs_pr(int nd){
if(pr[nd]){
	int mxi = 0;
	if(ind[pr[nd]][0]==nd) mxi = 1;
	int mxp=mx[pr[nd]][mxi];
	add_mx(nd, mxp+1, pr[nd]);
}
for(auto nc: t[nd])
	if(nc!=pr[nd])
		dfs_pr(nc);
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin >> n >> m >> d;
RE(i, 0, m){
	cin >> p[i];
	c[p[i]] = 1;
}
RE(i, 0, n-1){
	int a, b;
	cin >> a >> b;
	t[a].push_back(b);
	t[b].push_back(a);
}
RE(i, 1, n+1){
	mx[i][0] = mx[i][1] = -1;
	ind[i][0] = ind[i][1] = -1;
}
dfs(1, 0);
dfs_pr(1);
int ans=0;
RE(i, 1, n+1)
	if(mx[i][0]>=0 && mx[i][0]<=d)
		ans++;
cout << ans << '\n';
}

//08:44 21-01-2019
