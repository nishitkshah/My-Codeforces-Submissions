//00:24 05-07-2019 to 00:36 05-07-2019
//23:53 09-07-2019
//00:12 10-07-2019
//00:15 10-07-2019

#include<bits/stdc++.h>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ (2001*100)

int n, m, x, y;
set<int> g[N_], rg[N_], uv1, uv2;
stack<int> ts;
vector<int> scc[N_], sz;

void dfs1(int nd){
//cerr << "D: " << nd << endl;
if(!uv1.count(nd)) return;
uv1.erase(nd);
int nc = -1;
auto lb = uv1.lower_bound(nc);
while(lb!=uv1.end()){
	nc = *lb;
	if(!g[nd].count(nc)){
		//cout << "C: " << nd << " " << nc << endl;
		dfs1(nc);
	}
	nc++;
	lb = uv1.lower_bound(nc);
}
ts.push(nd);
}

void dfs2(int nd, int cmp){
if(!uv2.count(nd)) return;
uv2.erase(nd);
scc[cmp].push_back(nd);
int nc = -1;
auto lb = uv2.lower_bound(nc);
//for(auto nc: uv2)	//Iterator gets invalidated after erase called on uv2 during recursion
while(lb!=uv2.end()){
	nc = *lb;
	if(!rg[nd].count(nc))
		dfs2(nc, cmp);
	nc++;
	lb = uv2.lower_bound(nc);
}
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> m;
RE(i, 0, m){
	cin >> x >> y;
	g[x].insert(y);
	rg[y].insert(x);
}
RE(i, 1, n+1) uv1.insert(i), uv2.insert(i);
//for(auto nc: uv1)
//	cerr << "UV1: " << nc << endl;
//for(auto nc: uv2)
//	cerr << "UV2: " << nc << endl;
RE(i, 1, n+1) dfs1(i);
//RE(i, 1, n+1) dfs2(i, i);
while(ts.size()){
	int v = ts.top();
	ts.pop();
	dfs2(v, v);
}
RE(i, 1, n+1)
	if(scc[i].size())
		sz.push_back(scc[i].size());
sort(sz.begin(), sz.end());
cout << sz.size() << '\n';
RE(i, 0, sz.size()){
	if(i) cout << ' ';
	cout << sz[i];
}
cout << '\n';
}

//00:10 10-07-2019
//00:14 10-07-2019
//00:34 10-07-2019
//00:39 10-07-2019
