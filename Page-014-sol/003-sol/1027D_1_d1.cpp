//18:26 19-10-2018
//18:33 19-10-2018
//19:02 19-10-2018

#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define SI(a) scanf("%d", &(a))
#define N_ 200000
#ifdef DBG
	#define PI(a) cerr << #a ": " << a << '\n'
	#define PA(a, i, s, f) cerr << #a ":"; RE(i, s, f) cerr << " " << a[i]; cerr << '\n'
#endif
#ifndef DBG
	#define PI(a)
	#define PA(a, i, s, f)
#endif

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
PI(ct);
PA(c, i, 0, n);
PA(a, i, 0, n);
PA(cmp, i, 0, n);
PA(sz, i, 0, ct);
PA(pt, i, 0, ct);
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
	PI(c[st]);
	RE(j, 0, sz[i]){
		st = a[st];
		PI(c[st]);
		mn = min(mn, c[st]);
	}
	cost += mn;
}
printf("%lld\n", cost);
}

//18:55 19-10-2018
//19:36 19-10-2018
//19:36 19-10-2018
