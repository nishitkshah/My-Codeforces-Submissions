#include<iostream>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int n, s[502], pal[502][502], dp[502][502];

int main(){
	ios::sync_with_stdio(0);
	cin >> n;
	REP(i, 0, n) cin >> s[i];
	REP(i, 0, n)
		REP(j, 0, n+1) pal[i][j] = dp[i][j] = 0;
	REP(i, 0, n){
		REP(j, 0, n+1){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	REP(i, 0, n){
		REP(j, 0, n+1){
			cout << pal[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	REP(i, 0, n){
		REP(l, 1, n+1-i){
			if(l==1) pal[i][l] = 1;
			else{
				if(l==2)
					if(s[i]==s[i+1]) pal[i][l] = 1;
				else
					if(s[i]==s[i+l-1]) pal[i][l] = pal[i+1][l-2];
			}
		}
	}
/*	REP(i, 0, n){
		REP(j, 0, n+1){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	REP(i, 0, n){
		REP(j, 0, n+1){
			cout << pal[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;	*/
	REP(i, 0, n){
		REP(l, 1, n+1-i){
			if(pal[i][l]) dp[i][l] = 1;
			else{
				int mn = 1000;
				REP(j, 1, l){
					mn = min(mn, dp[i][j]+dp[i+j][l-j]);
				}
				dp[i][l] = mn;
			}
		}
	}
	REP(i, 0, n){
		REP(j, 0, n+1){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	REP(i, 0, n){
		REP(j, 0, n+1){
			cout << pal[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << dp[0][n];
	return 0;
}
