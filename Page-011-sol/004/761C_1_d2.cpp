//19:31 13-08-2018
//19:40 13-08-2018
//19:54 13-08-2018
//19:58 13-08-2018

#include<iostream>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAX 10000000

int n, m;
char c[50][51];

int get_alph(int ind){
	int mn=MAX;
	RE(i, 0, m)
		if(c[ind][i]>='a'&&c[ind][i]<='z')
			mn = min(mn, min(i, m-i));
	return mn;
}

int get_num(int ind){
	int mn=MAX;
	RE(i, 0, m)
		if(c[ind][i]>='0'&&c[ind][i]<='9')
			mn = min(mn, min(i, m-i));
	return mn;
}

int get_sym(int ind){
	int mn=MAX;
	RE(i, 0, m)
		if(c[ind][i]=='#' || c[ind][i]=='*' || c[ind][i]=='&')
			mn = min(mn, min(i, m-i));
	return mn;
}

main(){
	cin >> n >> m;
	RE(i, 0, n) cin >> c[i];
	int mn = MAX;
	int dp[50][3];
	RE(i, 0, n){
		dp[i][0] = get_alph(i);
		dp[i][1] = get_num(i);
		dp[i][2] = get_sym(i);
	}
	RE(i, 0, n)
		RE(j, 0, n)
			RE(k, 0, n)
				if(i!=j && j!=k && k!=i)
					mn = min(mn, dp[i][0]+dp[j][1]+dp[k][2]);
	cout << mn << '\n';
}

//19:53 13-08-2018
//19:56 13-08-2018
//20:00 13-08-2018
//20:03 13-08-2018
