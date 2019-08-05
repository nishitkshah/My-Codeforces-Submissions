//19:51 07-08-2018
//19:54 07-08-2018
//20:34 07-08-2018

#include<iostream>
#include<queue>
#include<algorithm>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

int n, m, k, cnt=0, vis[50][50]={0};
pair< int, pair<int, int> > p[2500];	//{sz, {x, y}}
char g[50][50];
queue< pair<int, int> > q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isVal(int x, int y){
	if(x<0 || y<0 || x>=n || y>=m)
		return false;
	return true;
}

int dfs(int x, int y, bool fill=false){
	if(vis[x][y] || g[x][y]!='.')
		return 0;
	q.push({x, y});
	vis[x][y] = 1;
	int cnt = 0;
	bool ocean = false;
	while(q.size()){
		pair<int, int> p = q.front();
		cnt++;
		int cx=p.first, cy=p.second;
		if(fill)
			g[cx][cy] = '*';
		q.pop();
		RE(i, 0, 4){
			int nx=cx+dx[i], ny=cy+dy[i];
			if(isVal(nx, ny)){
				if(!vis[nx][ny] && g[nx][ny]=='.'){
					q.push({nx, ny});
					vis[nx][ny] = 1;
				}
			}else{
				ocean = true;
			}
		}
	}
	if(ocean) return 0;
	return cnt;
}

main(){
	cin >> n >> m >> k;
	RE(i, 0, n)
		RE(j, 0, m)
			cin >> g[i][j];
	RE(i, 0, n){
		RE(j, 0, m){
			int c = dfs(i, j);
			if(c){
				p[cnt] = {c, {i, j}};
				cnt++;
			}
		}
	}
	RE(i, 0, n)
		RE(j, 0, m)
			vis[i][j] = 0;
	sort(p, p+cnt);
	int fill = 0;
	//cerr << "cnt: " << cnt << endl;
	//RE(i, 0, cnt)
	//	cerr << p[i].first << " " << p[i].second.first << " " << p[i].second.second << endl;
	//cerr << "Dbg ends\n";
	RE(i, 0, cnt-k){
		dfs(p[i].second.first, p[i].second.second, true);
		fill += p[i].first;
	}
	cout << fill << '\n';
	RE(i, 0, n){
		RE(j, 0, m)
			cout << g[i][j];
		cout << '\n';
	}
}

//20:33 07-08-2018
//20:44 07-08-2018
//20:45 07-08-2018
