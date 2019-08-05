//20:52 12-07-2018
//20:57 12-07-2018

#include<iostream>
#include<string>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MOD 1000000007

int n, m, cnt[100][26];

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	RE(i, 0, n){
		string s;
		cin >> s;
		RE(j, 0, m) cnt[i][s[i]-'A']++;
	}
	int c;
	long long ans = 1LL;
	RE(j, 0, m){
		c = 0;
		RE(i, 0, n)
			if(cnt[i][j]) c++;
		ans *= c;
		ans %= MOD;
	}
	cout << ans << '\n';
}

//21:05 12-07-2018
