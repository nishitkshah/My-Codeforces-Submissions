//01:13 26-04-2019 to 01:23 26-04-2019 and 23:20 31-05-2019 to 23:34 31-05-2019
//08:10 02-06-2019
//08:37 02-06-2019
//08:40 02-06-2019
//08:43 02-06-2019

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ (100 * 1001)

int n, m, s, c[N_], vis[N_][2] = {0}, vis2[N_]={0}, path[N_]={0}, pl=0;
vector<int> t[N_];
bool win = false, loop = false;

void dfs(int nd, int len=0){
if(win || vis[nd][len%2]) return;
vis[nd][len%2] = 1;
path[len] = nd;
if((len%2) && !c[nd] && !win){
	win = true;
	pl = len+1;
}
for(auto nc: t[nd])
	dfs(nc, len+1);
}

void cycle(int nd){
if(loop) return;
if(vis2[nd]==1) loop = true;
if(vis2[nd]) return;
vis2[nd] = 1;
for(auto nc: t[nd])
	cycle(nc);
vis2[nd] = 2;
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin >> n >> m;
RE(i, 0, n){
	cin >> c[i];
	int u;
	RE(j, 0, c[i]){
		cin >> u;
		t[i].push_back(u-1);
	}
}
cin >> s;
s--;
dfs(s);
if(win){
	cout << "Win\n";
	RE(i, 0, pl){
		if(i) cout << ' ';
		cout << path[i]+1;
	}
	cout << '\n';
	return 0;
}
cycle(s);
if(loop) cout << "Draw\n";
else cout << "Lose\n";
}

//08:36 02-06-2019
//08:39 02-06-2019
//08:41 02-06-2019
//08:46 02-06-2019
//08:47 02-06-2019
