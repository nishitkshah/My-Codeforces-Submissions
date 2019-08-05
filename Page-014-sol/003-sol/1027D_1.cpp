//18:26 19-10-2018
//18:33 19-10-2018

#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define SI(a) scanf("%d", &(a))
#define N_ 200000


int n, c[N_], a[N_], cmp[N_]={0}, sz[N_]={0}, pt[N_];
vector<int> g[N_];

void dfs(int n, int c){
	if(!cmp[n]){
		cmp[n] = c;
		sz[c-1]++;
		RE(i, 0, g[n].size()){
			dfs(g[n][i], c);
		}
	}
}

main(){
SI(n);
RE(i, 0, n) SI(c[i]);
RE(i, 0, n){
	SI(a[i]);
	a[i]--;
	g[i].push_back(a[i]);
	g[a[i]].push_back(i);
}
int ct=0;
RE(i, 0, n){
	if(!cmp[i]){
		pt[ct] = i;
		ct++;
		dfs(i, ct);
	}
}
RE(i, 0, n) cmp[i]--;
long long cost = 0LL;
RE(i, 0, ct){
	//For each component, get a node in cycle and store it in pt array
	int st = pt[i];
	RE(i, 0, sz[i]){
		st = a[st];
	}
	pt[i] = st;
	//Find min cost for the cycle
	//This will suffice as atleast one of cycle would have to be covered
	int mn = c[st];
	RE(i, 0, sz[i]){
		st = a[st];
		mn = min(mn, c[st]);
	}
	cost += mn;
}
printf("%lld\n", cost);
}

//18:55 19-10-2018
//19:00 19-10-2018
