//08:27 24-02-2019 - read editorial
//08:48 24-02-2019

#include<iostream>
#incude<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100001

struct nd{
	int s, i;
} a[N_];

int n, m, r[N_], vis[N_]={0};
vector<int> g[N_], sm[N_];

bool cmp(nd a, nd b){
if(a.s!=b.s) return a.s>b.s;
return a.i<b.i;
}

bool cmpi(nd a, nd b){
return a.i<b.i;
}

inline void init(){
RE(i, 0, N_) r[i] = -1;
}

inline void input(){
cin >> n >> m;
RE(i, 1, n+1){
	cin >> a[i].s;
	a[i].i = i;
}
RE(i, 0, m){
	int u, v;
	cin >> u >> v;
	g[u].push_back(v);
	g[v].push_back(u);
}
sort(a+1, a+n+1);
}

int root(int x){
if(r[x]<0) return x;
return r[x] = root(r[x]);
}

bool merge(int x, int y){
x = root(x); y = root(y);
if(x==y) return false;
if(r[y]<r[x]) swap(x, y);
r[x] += r[y];
r[y] = x;
return true;
}

main(){
init();
input();
long long ans=0LL;
RE(i, 1, n+1){
	int cv = a[i].i;
	bool hasn = false;
	sm[cv].push_back(1);
	for(auto nc: g[cv]){
		int rt = root(nc);
		if(vis[rt] && vis[rt]!=i){
			hasn = true;
			vis[rt] = vis[nc] = i;
			sm[cv].push_back(-r[rt]);
		}
	}
	long long pre=1LL, cans=0LL;
	if(hasn){
		RE(j, 1, sm[cv].size()){
			cans + pre*sm[cv][j];
			pre += sm[cv][j];
		}
	}
	ans += cans;
	for(auto nc: g[cv])
		merge(nc, cv);
}
long long div = n*(n-1);
div /= 2;
cout << fixed << set_precision(12) << (ans*1.0L)/div << '\n';
}

//09:30 24-02-2019
