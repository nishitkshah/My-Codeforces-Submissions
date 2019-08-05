//01:12 21-06-2019 to 01:26 21-06-2019
//22:12 02-07-2019
//22:34 02-07-2019

#include<bits/stdc++.h>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ (200 * 1001)
#define INF (100 * 1000LL * 1000 * 1000 * 1000LL)
#define FF first
#define SS second

typedef pair< long long, pair<int, int> > edge;

int n, m, x[N_], y[N_], mi=-1, r[N_];
long long a[N_], w[N_], mv=INF, ans=0LL;

int root(int x){
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

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> m;
RE(i, 1, n+1) cin >> a[i];
RE(i, 1, m+1) cin >> x[i] >> y[i] >> w[i];
RE(i, 1, n+1)
	if(mv>a[i])
		mi=i, mv=a[i];
vector<edge> g;
RE(i, 1, n+1)
	if(i!=mi)
		g.push_back({a[i]+a[mi], {i, mi}});
RE(i, 1, m+1) g.push_back({w[i], {x[i], y[i]}});
RE(i, 1, n+1) r[i] = -1;
sort(g.begin(), g.end());
//for(auto e: g) cerr << e.FF << ' ' << e.SS.FF << ' ' << e.SS.SS << '\n';
for(auto e: g)
	if(merge(e.SS.FF, e.SS.SS))
		ans += e.FF;
cout << ans << '\n';
}

//22:32 02-07-2019
//22:47 02-07-2019
//22:48 02-07-2019
