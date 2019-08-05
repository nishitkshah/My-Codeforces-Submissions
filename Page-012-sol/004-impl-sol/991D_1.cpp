//11:47 17-08-2018
//11:49 17-08-2018

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string s[2];
int n, dp[100][4];

sting p[4][2] = {
	{"XX", "X."},
	{"XX", ".X"},
	{".X", "XX"},
	{"X.", "XX"}
};

bool match(int pos, int pat){
	RE(i, 0, 2){
		RE(j, 0, 2){
			if(s[i][pos+j]==p[pat][i][j])
				return false;
		}
	}
	return true;
}

int calc(int pos, int pat){
	if(!match(pos, pat))
		return dp[pos][pat] = 0;
	int mx = 0;
	if(pos>1){
		RE(i, 0, 4){
			mx = max(mx, dp[pos-2][i]);
		}
	}
	if(pos && (pat==0 || pat==3)){
		int fit = (pat+2)%4;
		mx = max(mx, dp[pos-1][fit]);
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
	cout << mx << '\n';
}

//12:26 17-08-2018
