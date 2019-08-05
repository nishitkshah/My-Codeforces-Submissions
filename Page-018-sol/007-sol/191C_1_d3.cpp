//00:51 23-01-2019 to 01:04 23-01-2019
//20:16 23-01-2019
//21:00 23-01-2019
//21:12 23-01-2019
//21:41 23-01-2019

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100000
#define LG_ 17

int n, k, lgn, pr[N_][LG_], dpt[N_], cnt[N_]={0}, cnte[N_]={0};
vector<int> t[N_], ei[N_];
pair<int, int> e[N_];

void dfs(int nd, int par, int dth){
int pi = 0, pt = par;
dpt[nd] = dth;
pr[nd][pi] = par;
while(pt!=-1 && (pi+1)<lgn){
	pr[nd][pi+1] = pr[pt][pi];
	pt = pr[nd][pi+1];
	pi++;
}
for(auto nc: t[nd])
	if(nc!=par)
		dfs(nc, nd, dth+1);
}

inline int lca(int x, int y){
//get them to same level
if(dpt[y]>dpt[x]) swap(x, y);
int i = lgn-1;
while(dpt[x]!=dpt[y]){
	if(pr[x][i]!=-1 && dpt[pr[x][i]]>=dpt[y])
		x = pr[x][i];
	i--;
}
//Return if same
if(x==y) return x;
//Move up while par not same
for(i=lgn-1; i>=0; i--){
	if(pr[x][i]!=pr[y][i]){
		x = pr[x][i];
		y = pr[y][i];
	}
}
return pr[x][0];
}

int dfs_cnt(int nd){
int ans=0, ansc=0;
RE(i, 0, t[nd].size()){
	int nc = t[nd][i], ec = ei[nd][i];
	if(nc!=pr[nd][0]){
		ansc = dfs_cnt(nc);
		cnte[ec] += ansc;
		ans += ansc;
	}
}
return ans + cnt[nd];
}

inline void init(){
RE(i, 0, n)
	RE(j, 0, lgn)
		pr[i][j] = -1;
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin >> n;
lgn = 1;
while((1<<lgn)<n) lgn++;
init();
RE(i, 0, n-1){
	int x, y;
	cin >> x >> y;
	x--, y--;
	e[i].first = x;
	e[i].second = y;
	t[x].push_back(y);
	t[y].push_back(x);
	ei[x].push_back(i);
	ei[y].push_back(i);
}
dfs(0, -1, 0);
cin >> k;
RE(i, 0, k){
	int x, y, l;
	cin >> x >> y;
	x--; y--;
	l = lca(x, y);
	cnt[x]++;
	cnt[y]++;
	cnt[l] -= 2;
}
dfs_cnt(0);
RE(i, 0, n-1){
	if(i) cout << ' ';
	cout << cnte[i];
}
cout << '\n';
}

//21:00 23-01-2019
//21:11 23-01-2019
//21:40 23-01-2019
//21:42 23-01-2019
