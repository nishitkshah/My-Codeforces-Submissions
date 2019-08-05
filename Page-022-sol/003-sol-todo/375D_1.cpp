//08:40 23-04-2019 to 08:53 23-04-2019
//22:12 24-04-2019

#include<iostream>
#include<vector>
#include<unordered_map>
#include<utility>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ (100 * 1001)
#define FF first
#define SS second
#define IN(v, mp) (mp.count(v))

int n, m, c[N_], id[N_];
pair<int, int> q[N_];
vector<int> t[N_];
unordered_map<int, int> clc[N_];
unordered_map<int, int> cnc[N_];

void dfs(int nd, int rt=0){
int &mx=id[nd], mn;
if(IN(1, cnc[mx]))
	cnc[mx][1] = 1;
for(auto nc: t[nd]){
	if(nc!=rt){
		mn = id[nc];
		if(mx.size()<mn.size())
			swap(mx, mn);
		for(auto pi: clc[mn]){
			int v=pi.FF, cnt=pi.SS;
			if(IN(v, clc[mx])){
				if(IN(clc[mx][v], cnc[mx]))
					cnc[mx][clc[mx][v]]--;
				clc[mx][v] += cnt;
				if(IN(clc[mx][v], cnc[mx]))
					cnc[mx][clc[mx][v]]++;
			}else{
				clc[mx][v] = cnt;
				if(IN(clc[mx][v], cnc[mx]))
					cnc[mx][clc[mx][v]]++;
			}
		}
	}
}
//id[nd] = mx;
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> m;
RE(i, 1, n+1){
	cin >> c[i];
	id[i] = i;
	clc[i][c[i]] = 1;
}
RE(i, 1, n){
	int u, v;
	cin >> u >> v;
	t[u].push_back(v);
	t[v].push_back(u);
}
RE(i, 0, m){
	cin >> q[i].FF >> q[i].SS;
	cnc[q[i].FF][q[i].SS] = 0;
}
dfs(1);
RE(i, 0, m)
	cout << cnc[q[i].FF][q[i].SS] << '\n';
}

//22:45 24-04-2019
