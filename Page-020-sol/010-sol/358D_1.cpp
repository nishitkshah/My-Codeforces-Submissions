//23:56 03-03-2019 to 00:07 04-03-2019 and 19:45 07-03-2019 to 19:54 07-03-2019 - read editorial
//19:54 07-03-2019

#include<iostream>
#include<algorithm>

using namespace std;

//#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 3001

int n, a[3][N_], dp[2][N_];

main(){
cin >> n;
RE(i, 0, 3)
	RE(j, 0, n) cin >> a[i][j];
dp[0][n-1] = a[0][n-1]; dp[1][n-1] = a[1][n-1];
for(int i=n-2; i>=0; i--){
	dp[0][i] = max(a[0][i]+dp[1][i+1], a[1][i]+dp[0][i+1]);
	dp[1][i] = max(a[1][i]+dp[1][i+1], a[2][i]+dp[0][i+1]);
}
dp[1][0] = 0
cout << dp[0][0] << '\n';
}

//20:02 07-03-2019
