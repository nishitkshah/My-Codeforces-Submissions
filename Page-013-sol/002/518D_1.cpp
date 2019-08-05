//15:37 21-08-2018
//15:39 21-08-2018

#include<iostream>
#include<iomanip>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAX 2001

int n, t;
long double p, dp[MAX][MAX]={0.0L};

main(){
	cin >> n >> p >> t;
	dp[0][0] = 1.0L;
	RE(i, 1, t+1){
		dp[i][0] = dp[i-1][0]*(1-p);
		RE(j, 1, n+1){
			if(j!=n)
				dp[i][j] = dp[i-1][j]*(1-p);
			else
				dp[i][j] = dp[i-1][j];
			dp[i][j] += dp[i-1][j-1]*p;
		}
	}
	long double ans = 0.0L;
	RE(i, 0, n+1)
		ans += i*dp[t][i];
	cout << fixed << setprecision(9) << ans << '\n';
}

//15:52 21-08-2018
//15:54 21-08-2018
