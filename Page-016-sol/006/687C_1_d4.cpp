//23:58 24-11-2018 to 00:02 25-11-2018
//15:12 02-12-2018
//15:28 02-12-2018
//15:31 02-12-2018
//15:33 02-12-2018
//15:36 02-12-2018

#include<iostream>

using namespace std;

#define N_ 501
#define RE(a, b, c) for(int a=(b); a<(c); a++)

int n, k, c[N_]={0}, dp[2][N_][N_]={0};

main(){
cin >> n >> k;
RE(i, 1, n+1) cin >> c[i];
dp[0][0][0] = 1;	//dp[a][b][c] = 'a'th coin, b sum, c subsum
RE(i, 1, n+1)
	RE(s, 0, k+1)
		RE(ss, 0, s+1){
			dp[i%2][s][ss] = dp[(i-1)%2][s][ss];
			if(s>=c[i] && (s-c[i])>=ss) dp[i%2][s][ss] = dp[i%2][s][ss] || dp[(i-1)%2][s-c[i]][ss];
			if(ss>=c[i]) dp[i%2][s][ss] = dp[i%2][s][ss] || dp[(i-1)%2][s-c[i]][ss-c[i]];
		}
int cnt=0;
RE(ss, 0, k+1)
	if(dp[n%2][k][ss])
		cnt++;
cout << cnt << '\n';
RE(ss, 0, k+1)
	if(dp[n%2][k][ss]){
		if(ss) cout << ' ';
		cout << ss;
	}
cout << '\n';
}

//15:27 02-12-2018
//15:28 02-12-2018
//15:31 02-12-2018
//15:34 02-12-2018
//15:38 02-12-2018
//15:39 02-12-2018
