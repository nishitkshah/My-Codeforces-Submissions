//08:27 24-02-2019 - read editorial
//08:48 24-02-2019
//09:31 24-02-2019
//09:35 24-02-2019
//10:17 24-02-2019

#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100001

struct nd{
	int s, i;
} a[N_];

int n, m, ao[N_], r[N_], vis[N_]={0};
vector<int> g[N_], sm[N_];

bool cmp(nd a, nd b){
if(a.s!=b.s) return a.s>b.s;
return a.i<b.i;
}

inline void init(){
RE(i, 0, N_) r[i] = -1;
}

inline void input(){
cin >> n >> m;
RE(i, 1, n+1){
	cin >> ao[i];
	a[i].s = ao[i];
	a[i].i = i;
}
RE(i, 0, m){
	int u, v;
	cin >> u >> v;
	g[u].push_back(v);
	g[v].push_back(u);
}
sort(a+1, a+n+1, cmp);
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
input();
init();
long long ans=0LL;
RE(i, 1, n+1){
	int cv = a[i].i;
	vis[cv] = cv;
	//bool hasn = false;	//Not needed
	sm[cv].push_back(1);
	for(auto nc: g[cv]){
		int rt = root(nc);
		if(vis[rt] && vis[rt]!=cv){
			//hasn = true;
			vis[rt] = vis[nc] = cv;
			sm[cv].push_back(-r[rt]);
		}
	}
	long long pre=1LL, cans=0LL;
	//if(hasn){
	RE(j, 1, sm[cv].size()){
		cans += pre*sm[cv][j];
		pre += sm[cv][j];
	}
	//}
	ans += ao[cv]*cans;
	for(auto nc: g[cv])
		if(vis[root(nc)]==cv)
			merge(nc, cv);
}
long long div = ((long long)n)*(n-1);
div /= 2;
cout << fixed << setprecision(12) << ((long double)ans)/div << '\n';
cerr << ans << ' ' << div << '\n';
}

//09:30 24-02-2019
//09:34 24-02-2019
//10:03 24-02-2019
//10:31 24-02-2019
//10:32 24-02-2019
