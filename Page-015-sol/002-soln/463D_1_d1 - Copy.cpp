//10:01 23-10-2018
//10:03 23-10-2018 to 10:11 23-10-2018 and 23:16 23-10-2018
//23:52 23-10-2018

#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 1000

int n, k, s[N_][5], dp[N_][N_], dir[N_][N_], l, ls[N_];

main(){
cin >> n >> k;
RE(i, 0, k)
	RE(j, 0, n) cin >> s[j][i];
l = n;
RE(i, 0, n) ls[i] = s[i][0];
RE(si, 1, k){
	cerr << "Match: " << si-1 << " " << si << ":\n";
	dp[0][0] = (s[0][si]==ls[0]) ? 1 : 0;
	dir[0][0] = 0;	//Can't move anywhere
	RE(i, 1, n)
		if(s[i][si]==ls[0]) dp[i][0] = 1, dir[i][0] = 0;
		else dp[i][0] = dp[i-1][0], dir[i][0] = 1;
	RE(i, 1, l)
		if(ls[i]==s[0][si]) dp[0][i] = 1, dir[0][i] = 0;
		else dp[0][i] = dp[0][i-1], dir[0][i] = -1;
	RE(i, 1, n)
		RE(j, 1, l){
			if(s[i][si]==ls[j]){
				dp[i][j] = dp[i-1][j-1]+1;
				dir[i][j] = 0;
				continue;
			}
			if(dp[i-1][j]<dp[i][j-1]){
				dp[i][j] = dp[i][j-1];
				dir[i][j] = -1;
			}else{
				dp[i][j] = dp[i-1][j];
				dir[i][j] = 1;
			}
		}
	int nl = dp[n-1][l-1];
	int x=n-1, y=l-1;
	for(int i=nl-1; i>=0; i--){
		while(dir[x][y])
			if(dir[x][y]==1) x--;
			else y--;
		cerr << "X Y dir[x][y]: " << x << " " << y << " " << dir[x][y] << "\n";
		ls[i] = s[x][si];
		x--, y--;
	}
	cerr << "DP:\n";
	RE(i, 0, n){
		RE(j, 0, l) cerr << dp[i][j] << ' ';
		cerr << '\n';
	}
	cerr << "DIR:\n";
	RE(i, 0, n){
		RE(j, 0, l) cerr << dir[i][j] << '\t';
		cerr << '\n';
	}
	l = nl;
	cerr << "LCS:\n";
	RE(i, 0, l) cerr << ls[i] << ' ';
	cerr << '\n';
}
cout << l << '\n';
}

//23:42 23-10-2018
//00:14 24-10-2018
