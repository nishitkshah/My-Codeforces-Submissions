//18:07 22-02-2019 - read editorial
//18:35 22-02-2019 to 18:54 22-02-2019 and 23:04 22-02-2019

#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<string>

using namspace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 2001
#define S_ N_*N_

int n, m, pcnt[N_][N_]={0};
string g[N_];
char c[N_][N_];
vector< pair<int, int> > v[N_][N_];
int dx[] = {1, 0};
int dy[] = {0, 1};
queue< pair<int, int> > q;

void color(int cx, int cy, int nx, int ny){
if(cx!=nx){
	if(cx>nx) swap(cx, nx);
	c[cx][cy] = '<';
	c[nx][ny] = '>';
}else{
	if(cy>ny) swap(cy, ny);
	c[cx][cy] = '^';
	c[nx][ny] = 'v';
}
}

void disconnect(pair<int, int> p){
pcnt[p.first][p.second]--;
}

main(){
cin >> n >> m;
RE(i, 0, n)
	cin >> g[i];
RE(i, 0, n-1){
	RE(j, 0, m-1){
		if(g[i][j]=='.')
			RE(k, 0, 2){
				int nx=i+dx[k], ny=j+dy[k];
				if(g[nx][ny]=='.'){
					v[i][j].push_back({nx, ny});
					v[nx][ny].push_back({i, j});
					pcnt[i][j]++;
					pcnt[nx][ny]++;
				}
			}
	}
}
RE(i, 0, n)
	RE(j, 0, m){
		c[i][j] = g[i][j];
		if(pcnt[i][j]==1)
			q.push({i, j});
	}
while(q.size()){
	auto pr = q.front();
	q.pop();
	int cx=pr.first, cy=pr.second;
	if(!vis[cx][cy]){
		vis[cx][cy] = 1;
		pair<int, int> pc;
		for(auto p: v[cx][cy])
			if(!vis[p.first][p.second])
				pc = p;
		int nx=pc.first, ny=pc.second;
		vis[nx][ny] = 1;
		color(cx, cy, nx, ny);
		disconnect({cx, cy});
		for(auto p: v[nx][ny])
			if(!vis[p.first][p.second]){
				disconnect(p);
				disconnect({nx, ny});
				if(pcnt[p.first][p.second]==1)
					q.push(p);
			}
	}
}
bool valid=true;
RE(i, 0, n)
	RE(j, 0, m)
		if(c[i][j]=='.')
			valid = false;
if(valid)
	RE(i, 0, n){
		RE(j, 0, m)
			cout << c[i][j];
		cout << '\n';
	}
else
	cout << "Not unique\n";
}

//23:39 22-02-2019
