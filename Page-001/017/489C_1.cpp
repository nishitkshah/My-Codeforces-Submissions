//18:37 16-05-2018
//18:40 16-05-2018

#include<iostream>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int m, s, dp[110][910] = {0};

int main(){
	cin >> m >> s;
	REP(i, 1, 10) dp[1][i] = 1;
	REP(i, 1, m)
		REP(j, 1, s+1)
			REP(k, 0, 10)
				if((j+k)<=s)
					dp[i+1][j+k] += dp[i][j];
	cout << dp[m][s] << '\n';	// This is not what is asked in the question
	return 0;
}

//18:48 16-05-2018
