//14:03 20-08-2018 to 14:10 20-08-2018
//15:04 20-08-2018

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

int n, dp[4][2]={0}, ord[]={0, 1, 2, 3};
string s[4][100];

int calc(int ind, int b){
	int cnt = 0;
	RE(i, 0, n){
		RE(j, 0, n){
			if((s[ind][i][j]-'0')!=((b+i+j)%2)) cnt++;
		}
	}
	return cnt;
}

main(){
	cin >> n;
	RE(i, 0, 4){
		RE(j, 0, n) cin >> s[i][j];
		RE(j, 0, 2) dp[i][j] = calc(i, j);
	}
	
	int mn = 4000000;
	do{
		int sum = 0;
		RE(i, 0, 4){
			sum += dp[i][ord[i]%2];
		}
		mn = min(sum, mn);
	}while(next_permutation(ord, ord+4));
	
	cout << mn << '\n';
}

//15:15 20-08-2018
//15:16 20-08-2018
