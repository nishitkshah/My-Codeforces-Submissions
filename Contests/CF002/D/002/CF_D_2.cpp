#include<iostream>
#include<algorithm>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int n, s[502], dp[502][502];

int main(){
	ios::sync_with_stdio(0);
	cin >> n;
	REP(i, 0, n) cin >> s[i];
	REP(i, 0, n)
		REP(j, 0, n+1) dp[i][j] = 10000;
	REP(l, 1, n+1){
		REP(i, 0, n-l+1){
			if(l==1) dp[i][l] = 1;
			else{
				if(l==2){
					if(s[i]==s[i+1]) dp[i][l] = 1;
					else dp[i][l] = 2;
				}else{
					if(s[i]==s[i+l-1]){
						if(s[i+1]==s[i+l-2]){
							dp[i][l] = dp[i+1][l-2];
						}else{
							dp[i][l] = 1+dp[i+1][l-2];
							if(l>3){
								dp[i][l] = min(dp[i][l], 1+dp[i+2][l-2]);
								dp[i][l] = min(dp[i][l], 1+dp[i+1][l-3]);
							}
						}
					}else{
						dp[i][l] = 1+min(dp[i][l-1], dp[i+1][l-1]);
					}
				}
			}
		}
	}
	cout << dp[0][n];
	return 0;
}
