//22:26 30-05-2018
//22:28 30-05-2018

#include<iostream>
#include<algorithm>

using namespace std;

int dp[11] = {0};

main(){
	long long n, d=0, t=0;
	cin >> n;
	for(int i=1; i<11; i++) dp[i] = dp[i-1]*10+9;
	for(int i=1; i<11; i++){
		t = min(n, dp[i]);
		d += i*(t-dp[i-1]);
		if(dp[i]>=n) break;
	}
	cout << d << "\n";
}

//22:32 30-05-2018
