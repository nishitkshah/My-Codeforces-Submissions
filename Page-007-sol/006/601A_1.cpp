//13:28 01-07-2018 - Read it before
//13:32 01-07-2018

#include<iostream>
#include<queue>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int n, m;
int t[400][400]={0}, b[400][400]={0};
int v[400]={0};

void ins(int cv, queue<int> &q, int d){
	if(!v[cv]){
		v[cv] = d;
		q.push(cv);
	}
}

int bfs(int g[400][400]){
	int cv = 0;
	queue<int> q;
	ins(cv, q, 1);
	while(q.size()){
		cv = q.front();
		if(cv==(n-1)) return v[cv]-1;
		q.pop();
		REP(i, 0, n)
			if(g[cv][i]) ins(i, q, v[cv]+1);
	}
	return -1;
}

main(){
	int a, b;
	cin >> n >> m;
	REP(i, 0, m){
		cin >> a >> b;
		a--; b--;
		t[a][b] = 1;
		t[b][a] = 1;
	}
	REP(i, 0, n)
		REP(j, 0, n)
			if((!t[i][j])&&(i!=j)) b[i][j] = 1;
	int d=0;
	if(t[0][n-1]==1) d = bfs(b);
	else d = bfs(t);
	cout << d << '\n';
}

//13:54 01-07-2018
