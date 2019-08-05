//21:35 25-10-2018
//21:59 25-10-2018 to 22:08 25-10-2018 and 08:48 30-10-2018

#include<iostream>
#include<vector>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 200000
#define GREEN 0
#define RED 1

int n, vis[N_]={0}, rc=0, gc=0, r[N_]={0}, g[N_]={0}, ans[N_];
vector<int> v[N_], c[N_];

void dfs(int n, int cp=-1, int rp=0, int pl=0){
	if(!vis[n]){
		vis[n] = 1;
		if(cp==RED) rc++;
		r[n] = rp;
		g[n] = pl-rp;
		RE(i, 0, v[n].size()){
			int nn = v[n][i];
			int nrp = rp + ( (c[n][i]==RED) ? 1 : 0 );
			dfs(nn, c[n][i], nrp, pl+1);
		}
	}
	if(cp==-1) gc = n-1 - rc;
}

main(){
cin >> n;
RE(i, 0, n-1){
	int s, t;
	cin >> s >> t;
	s--, t--;
	v[s].push_back(t); c[s].push_back(GREEN);
	v[t].push_back(s); c[t].push_back(RED);
}
dfs(0);
int mn=N_, mni=N_;
RE(i, 0, n){
	ans[i] = rc - r[i] + g[i];
	if(mn>=ans[i]){
		mn = ans[i];
		mni = i;
	}
}
cout << mni << '\n' << mn << '\n';
}

//09:06 30-10-2018
