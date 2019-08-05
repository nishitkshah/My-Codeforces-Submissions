//12:18 18-10-2018
//12:25 18-10-2018

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100000
#define C_ 100

int n, m, k, s, a[N_], d[N_][C_];
vector<int> v[N_], l[C_];

void bfs(int c){
	queue<int> q;
	int dt=0;
	for(auto e: l[c]) q.push(e);
	while(!q.empty()){
		int cn = q.front();
		dt = d[cn][c]+1;
		for(auto nn: v[cn]){
			if(d[nn][c]>dt){
				d[nn][c] = dt;
				q.push(nn);
			}
		}
		q.pop();
	}
}

main(){
	cin >> n >> m >> k >> s;
	RE(i, 0, n){
		cin >> a[i];
		a[i]--;
		RE(j, 0, k) d[i][j] = n+1;
		d[i][a[i]] = 0;
		l[a[i]].push_back(i);
	}
	RE(i, 0, m){
		int x, y;
		cin >> x >> y;
		x--; y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	RE(i, 0, k) bfs(i);
	RE(i, 0, n){
		sort(d[i], d[i]+k);
		int sm=0;
		RE(j, 0, s) sm += d[i][j];
		if(i) cout << ' ';
		cout << sm;
	}
	cout << '\n';
}

//12:55 18-10-2018
//13:02 18-10-2018
