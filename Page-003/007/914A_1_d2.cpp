//11:05 31-05-2018
//11:06 31-05-2018
//11:14 31-05-2018
//11:15 31-05-2018

#include<iostream>
#include<algorithm>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int dp[1000010] = {0};

main(){
	int n, a,mx=-1000010;
	cin >> n;
	REP(i, 0, 1001) dp[i*i] = 1;
	REP(i, 0, n){
		cin >> a;
		if(a<0||!dp[a]) mx = max(mx, a);
	}
	cout << mx << "\n";
}

//11:12 31-05-2018
//11:15 31-05-2018
//11:17 31-05-2018
//11:17 31-05-2018
