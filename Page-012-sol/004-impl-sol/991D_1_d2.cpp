//11:47 17-08-2018
//11:49 17-08-2018
//12:27 17-08-2018
//15:05 17-08-2018

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

#ifdef DBG
	#define PA2(a, i, j, n) cerr << #a #j ":"; RE(i, 0, n) cerr << ' ' << a[i][j]; cerr << '\n'
	#define PIII(a, b, c) cerr << #a ": " << a << " " #b ": " << b << " " #c ": " << c << '\n'
#endif
#ifndef DBG
	#define PA2(a, i, j, n)
	#define PIII(a, b, c)
#endif

string s[2];
int n, dp[100][4];

string p[4][2] = {
	{"XX", "X."},
	{"XX", ".X"},
	{".X", "XX"},
	{"X.", "XX"}
};

int match(int pos, int pat){
	RE(i, 0, 2){
		RE(j, 0, 2){
			if(s[i][pos+j]==p[pat][i][j])
				return 0;
		}
	}
	return 1;
}

int calc(int pos, int pat){
	int mt = match(pos, pat);
	PIII(pos, pat, mt);
	int mx = mt;
	if(pos>1){
		RE(i, 0, 4){
			mx = max(mx, dp[pos-2][i]+mt);
		}
	}
	if(pos){
		RE(i, 0, 4){
			mx = max(mx, dp[pos-1][i]);
		}
	}
	if(pos && (pat==1 || pat==2)){
		int fit = (pat+2)%4;
		mx = max(mx, dp[pos-1][fit]+mt);
	}
	return dp[pos][pat] = mx;
}

main(){
	cin >> s[0] >> s[1];
	n = s[0].size();
	int mx = 0;
	RE(pos, 0, n-1){
		RE(pat, 0, 4){
			mx = max(calc(pos, pat), mx);
		}
	}
	PA2(dp, i, 0, n);
	PA2(dp, i, 1, n);
	PA2(dp, i, 2, n);
	PA2(dp, i, 3, n);
	cout << mx << '\n';
}

//12:26 17-08-2018
//12:52 17-08-2018
//15:06 17-08-2018
//15:07 17-08-2018
