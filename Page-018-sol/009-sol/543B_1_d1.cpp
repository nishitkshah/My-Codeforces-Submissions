//00:23 26-01-2019 to 00:26 26-01-2019 and 15:17 26-01-2019 to 15:28 26-01-2019 - read editorial
//17:55 27-01-2019
//18:17 27-01-2019

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 3001

int n, m, vis[N_], s1, t1, l1, s2, t2, l2, d[N_][N_];
vector<int> g[N_];
queue<int> q;

void bfs(int nd){
vis[nd] = 1;
d[nd][nd] = 0;
q.push(nd);
while(q.size()){
	int nc = q.front();
	for(auto cc: g[nc]){
		if(!vis[cc]){
			vis[cc] = 1;
			d[nd][cc] = d[nd][nc]+1;
			q.push(cc);
		}
	}
	q.pop();
}
RE(i, 1, n+1) vis[i] = 0;
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> m;
RE(i, 0, m){
	int a, b;
	cin >> a >> b;
	g[a].push_back(b);
	g[b].push_back(a);
}
cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
RE(i, 1, n+1)
	bfs(i);
if(d[s1][t1]>l1 || d[s2][t2]>l2){
	cout << -1 << '\n';
	return 0;
}
int mx = m-d[s1][t1]-d[s2][t2];
RE(i, 1, n+1){
	RE(j, 1, n+1){
		int d1, d2;
		d1 = m-d[i][j]-d[s1][i]-d[s2][i]-d[t1][j]-d[t2][j];
		d2 = m-d[i][j]-d[s1][i]-d[t2][i]-d[t1][j]-d[s2][j];
		mx = max(mx, d1);
		mx = max(mx, d2);
	}
}
cout << mx << '\n';
}

//18:15 27-01-2019
//18:18 27-01-2019
//18:28 27-01-2019
