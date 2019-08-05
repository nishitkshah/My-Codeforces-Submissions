//11:05 31-05-2018
//11:06 31-05-2018

#include<iostream>
#include<algorithm>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int dp[1010] = {0};

main(){
	int n, a, t, mx=-1000010;
	cin >> n;
	REP(i, 0, 1001) dp[i*i] = 1;
	REP(i, 0, n){
		cin >> a;
		t = a;
		if(a<0) t = -a;
		if(!dp[t]) mx = max(mx, a);
	}
	cout << mx << "\n";
}

//11:12 31-05-2018
