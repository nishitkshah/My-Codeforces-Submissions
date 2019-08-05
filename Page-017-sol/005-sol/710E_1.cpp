//19:21 24-12-2018
//19:38 24-12-2018

#include<iostream>
#include<algorithm>

using namespace std;

#define N_ 10000001

int n, x, y;
long long dp[N_];

main(){
cin >> n >> x >> y;
dp[0] = 0LL;
for(int i=1; i<=n; i++){
	dp[i] = dp[i-1]+x;
	if(!(i&1)) dp[i] = min(dp[i], dp[i/2]+y);
}
cout << dp[n] << '\n';
}

//19:42 24-12-2018
//19:47 24-12-2018
