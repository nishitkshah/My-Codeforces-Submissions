//18:52 01-07-2018
//18:56 01-07-2018

#include<iostream>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

main(){
	int n, m, hb, hg, t, b[100]={0}, g[100]={0}, dp[100][100]={0};
	cin >> n >> m;
	cin >> hb;
	REP(i, 0, hb){
		cin >> t;
		b[t] = 1;
	}
	cin >> hg;
	REP(i, 0, hg){
		cin >> t;
		g[t] = 1;
	}
	REP(d, 0, 10000){
		if(dp[d%n][d%m]) break;
		dp[d%n][d%m] = 1;
		if(b[d%n]||g[d%m]){
			b[d%n] = g[d%m] = 1;
		}
	}
	bool unhappy = false;
	REP(i, 0, n) if(!b[i]) unhappy = true;
	REP(i, 0, m) if(!g[i]) unhappy = true;
	if(unhappy) cout << "NO\n";
	else cout << "YES\n";
}

//19:06 01-07-2018
//19:07 01-07-2018
