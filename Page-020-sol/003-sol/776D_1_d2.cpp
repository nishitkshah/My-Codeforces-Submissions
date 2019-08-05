//23:29 11-02-2019 - read editorial
//00:05 12-02-2019
//00:33 12-02-2019
//00:36 12-02-2019

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100001

int n, m, r[N_], st[N_];
vector<int> s[N_], d[N_], v[N_], e[N_];

void bfs(int nd){
queue<int> q;
q.push(nd);
st[nd] = 1;
while(q.size()){
	int cv = q.front();
	q.pop();
	RE(i, 0, v[cv].size()){
		int cc = v[cv][i];
		if(st[cc]==-1){
			if(e[cv][i]==1)
				st[cc] = st[cv];
			else
				st[cc] = 1-st[cv];
			q.push(cc);
		}
	}
}
}

main(){
cin >> n >> m;
RE(i, 1, n+1) cin >> r[i];
RE(i, 1, m+1){
	int x, xv;
	cin >> x;
	RE(j, 0, x){
		cin >> xv;
		s[i].push_back(xv);
		d[xv].push_back(i);
	}
}
RE(i, 1, n+1){
	int n1=d[i][0], n2=d[i][1];
	v[n1].push_back(n2);
	v[n2].push_back(n1);
	e[n1].push_back(r[i]);
	e[n2].push_back(r[i]);
}
RE(i, 1, m+1) st[i] = -1;
RE(i, 1, m+1)
	if(st[i]==-1)
		bfs(i);
bool valid = true;
RE(i, 1, n+1){
	int n1=d[i][0], n2=d[i][1];
	if(r[i]==1 && st[n1]!=st[n2]) valid = false;
	if(r[i]==0 && st[n1]==st[n2]) valid = false;
}
if(valid) cout << "YES\n";
else cout << "NO\n";
}

//00:32 12-02-2019
//00:33 12-02-2019
//00:37 12-02-2019
//00:38 12-02-2019
