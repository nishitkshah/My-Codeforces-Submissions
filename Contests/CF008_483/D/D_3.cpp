//20:55 15-05-2018
//20:58 15-05-2018 - D_1_d1.cpp
//21:48 15-05-2018 - D_3.cpp - modified from D_1.cpp

#include<iostream>
#include<algorithm>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

const int MAXN = 5010;

int a[MAXN], mx[5002][5002];

int main(){
	int n, q, l, r;
	cin >> n;
	REP(i, 1, n+1){
		cin >> a[i];
	}
	REP(j, 1, n+1){
		int ans = 0;
		mx[j][j] = a[j];
		for(int i=j; i>0; i--){
			ans ^= a[i];
			mx[i][j] = ans;
			if(i<j) mx[i][j] = max(mx[i][j], mx[i-1][j]);
			if((j>1)&&(i<j)) mx[i][j] = max(mx[i][j], mx[i][j-1]);
		}
	}
	cin >> q;
	REP(i, 0, q){
		cin >> l >> r;
		cout << mx[l][r] << "\n";
	}
	return 0;
}

//21:24 15-05-2018
//21:57 15-05-2018 - D_3
