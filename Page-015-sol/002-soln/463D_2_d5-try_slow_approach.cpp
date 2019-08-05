//21:43 24-10-2018
//21:50 24-10-2018 - coding begins for 463D_2.cpp
//22:42 24-10-2018
//00:04 25-10-2018
//00:11 25-10-2018
//00:19 25-10-2018
//00:21 25-10-2018

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 1001

int n, k, s[5][N_], rl[5][N_], vis[N_]={0};
vector<int> v[N_], d[2];
queue<int> ts;

void dfs(int n){
	if(!vis[n]){
		vis[n] = 1;
		RE(i, 0, v[n].size())
			dfs(v[n][i]);
		ts.push(n);
	}
}

main(){
cin >> n >> k;
RE(i, 0, k){
	s[i][0] = 0;
	rl[i][0] = 0;
	RE(j, 1, n+1){
		cin >> s[i][j];
		rl[i][s[i][j]] = j;
	}
}
RE(i, 0, n+1)
	RE(j, 0, n+1)
		if(i!=j){
			bool le = true;
			RE(si, 0, k)
				if(rl[si][i]>rl[si][j]){
					le = false;
					break;
				}
			if(le) v[i].push_back(j);
		}
d[0].push_back(0);
int l=-1;	//int l=0;
while(d[l+1].size()){
	l++;
	int ind = l%2;
	d[1-ind].clear();
	RE(i, 0, d[ind].size())
		RE(j, 0, v[d[ind][i]].size())
			d[1-ind].push_back(v[d[ind][i]][j]);
}
/*
dfs(0);
while(ts.size()){
	int e = ts.front();
	ts.pop();
	vis[e] = 0;
	RE(i, 0, v[e].size())
		vis[e] = max(vis[e], vis[v[e][i]]);
	vis[e]++;
}
cout << vis[0]-1 << '\n';
*/
cout << l << '\n';
}

//22:41 24-10-2018
//22:43 24-10-2018
//00:08 25-10-2018
//00:16 25-10-2018
//00:20 25-10-2018
//00:23 25-10-2018
//00:24 25-10-2018
