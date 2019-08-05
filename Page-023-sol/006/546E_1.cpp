//01:29 11-07-2019 to 01:39 11-07-2019 - read problem before
//22:10 11-07-2019 to 22:34 11-07-2019 and 22:51 11-07-2019

#include<bits/stdc++.h>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 300
#define INF 1000000

int n, m, a[N_], b[N_], cap[N_][N_]={0}, flow[N_][N_]={0}, par[N_], vis[N_]={0}, mf[N_]={0};
vector<int> g[N_], ag[N_];

int bfs(int s, int t){
RE(i, 0, 2*n+2) vis[i] = mf[i] = 0;
queue<int> q;
q.push_back(s);
par[s] = -1;
vis[s] = 1;
mf[s] = INF;
while(!q.empty()){
	int cv = q.top();
	q.pop();
	RE(auto nc: ag[cv]){
		if(!vis[nc] && cap[cv][nc]>0){
			par[nc] = cv;
			vis[nc] = vis[cv]+1;
			mf[nc] = min(cap[cv][nc], mf[cv]);
			if(nc==t)
				return mf[nc];
		}
	}
}
return 0;
}

int maxflow(int s, int t){
int mf=0, f=0;
while(f=bfs(s, t)){
	mf += f;
	int cv = t;
	while(cv!=s){
		cap[par[cv]][cv] -= f;
		cap[cv][par[cv]] += f;
		flow[par[cv]][cv] += f;
		flow[cv][par[cv]] -= f;
	}
}
return mf;
}

//Flow from node 0 to 2n+1
main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> m;
RE(i, 1, n+1) cin >> a[i];
RE(i, 1, n+1) cin >> b[i];
int suma=0, sumb=0;
RE(i, 1, n+1) suma += a[i], sumb += b[i];
if(suma!=sumb){
	cout << "NO\n";
	return 0;
}
RE(i, 1, n+1){
	ag[0].push_back(i);
	ag[i].push_back(n+i);
	ag[n+i].push_back(2*n+1);
	cap[0][i]=a[i];
	cap[i][n+i]=INF;
	cap[n+i][2*n+1]=b[i];
}
int p, q;
RE(i, 0, m){
	cin >> p >> q;
	g[p].push_back(q);
	g[q].push_back(p);
	ag[p].push_back(n+q);
	ag[q].push_back(n+p);
	ag[n+p].push_back(q);
	ag[n+q].push_back(p);
	cap[p][n+q] = INF;
	cap[q][n+p] = INF;
}
int mf = maxflow(0, 2*n+1);
if(mf==suma){
	cout << "YES\n";
	RE(i, 1, n+1){
		RE(j, 1, n+1){
			if(j!=1) cout << ' ';
			if(flow[i][n+j]>0) cout << flow[i][n+j];
			else cout << 0;
		}
		cout << '\n';
	}
}else
	cout << "NO\n";
}

//23:03 11-07-2019
