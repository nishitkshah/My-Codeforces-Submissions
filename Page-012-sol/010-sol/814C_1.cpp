//15:22 20-08-2018
//15:34 20-08-2018

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

string s;
int n, q, m, dp[26][1501];
char c;

void preprocess(){
	RE(cl, 0, 26){
		char ch = 'a'+cl;
		RE(ln, 1, n+1){
			int sm=0, mx;
			RE(l, 0, ln) sm += (s[l]==ch ? 1 : 0);
			mx = sm;
			for(int l=1, r=ln; r<n; l++, r++){
				sm -= (s[l-1]==ch ? 1 : 0);
				sm += (s[r]==ch ? 1 : 0);
				mx = max(mx, sm);
			}
			dp[cl][ln] = ln-mx;
		}
	}
}

void solve(){
	cin >> m >> c;
	int cl = c-'a';
	int p = upper_bound(dp[cl], dp[cl]+n, m)-dp[cl];
	p--;
	cout << p << '\n';
}

main(){
	cin >> n >> s >> q;
	preprocess();
	RE(i, 0, q){
		solve();
	}
}

//15:56 20-08-2018
