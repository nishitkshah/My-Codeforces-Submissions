//11:32 31-05-2018
//11:34 31-05-2018

#include<iostream>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int dp[101] = {1};

main(){
	REP(i, 0, 101-3) dp[i+3] += dp[i];
	REP(i, 0, 101-7) dp[i+7] += dp[i];
	int n, k;
	cin >> n;
	REP(i, 0, n){
		cin >> k;
		if(dp[k]) cout << "YES\n";
		else cout << "NO\n";
	}
}

//11:38 31-05-2018
//11:39 31-05-2018
