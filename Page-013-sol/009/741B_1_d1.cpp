//23:38 16-10-2018 to 23:57 16-10-2018
//21:03 17-10-2018
//22:13 17-10-2018

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 1000

int n, m, w, wa[N_], b[N_], vis[N_]={0}, dp[N_+1][2]={0};
vector<int> g[N_], wl[N_], bl[N_];

void dfs(int v, int c){
	if(vis[v]) return;
	vis[v] = c;
	for(auto nv: g[v])
		dfs(nv, c);
}

main(){
	cin >> n >> m >> w;
	RE(i, 0, n) cin >> wa[i];
	RE(i, 0, n) cin >> b[i];
	RE(i, 0, m){
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int cmp=0;
	RE(v, 0, n)
		if(!vis[v])
			dfs(v, ++cmp);
	RE(i, 0, cmp) wl[i].push_back(0), bl[i].push_back(0);	//To contain sums
	RE(i, 0, n){
		vis[i]--;	//Component 0 to cmp-1
		wl[vis[i]].push_back(wa[i]);
		bl[vis[i]].push_back(b[i]);
		wl[vis[i]][0] += wa[i];
		bl[vis[i]][0] += b[i];
	}
	RE(i, 0, cmp) wl[i].push_back(0), bl[i].push_back(0);	//When we don't choose any of the elements
	RE(i, 0, cmp){
		RE(j, 0, w+1) dp[j][i%2] = dp[j][1-(i%2)];
		RE(j, 0, wl[i].size()){
			int wc=wl[i][j], bc=bl[i][j], ic=i%2;
			if(wc<=w) dp[wc][ic] = max(dp[wc][ic], bc);
			RE(wp, 0, w+1){
				int ws=wc+wp;
				if(ws<=w) dp[ws][ic] = max(dp[ws][ic], bc+dp[wp][1-ic]);
			}
		}
	}
	int mx = 0;
	RE(i, 0, w+1) mx = max(mx, dp[i][(cmp-1)%2]);
	cout << mx << '\n';
}

//22:09 17-10-2018 - worked
//22:14 17-10-2018 - worked
//22:14 17-10-2018
