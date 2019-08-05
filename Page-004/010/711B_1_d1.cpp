//18:21 01-06-2018
//18:24 01-06-2018
//18:41 01-06-2018

#include<iostream>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int n, x, y;
long long t_sum=0LL, miss=0LL, a[500][500];

bool chk_diagonals(){
	long long sum = 0LL;
	REP(i, 0, n) sum += a[i][i];
	if(sum!=t_sum) return false;
	sum = 0LL;
	REP(i, 0, n) sum += a[i][n-1-i];
	if(sum!=t_sum) return false;
	return true;
}

bool chk_rows(){
	REP(i, 0, n){
		long long sum = 0LL;
		REP(j, 0, n) sum += a[i][j];
		if(sum!=t_sum) return false;
	}
	return true;
}

bool chk_cols(){
	REP(j, 0, n){
		long long sum = 0LL;
		REP(i, 0, n) sum += a[i][j];
		if(sum!=t_sum) return false;
	}
	return true;
}

main(){
	cin >> n;
	REP(i, 0, n) REP(j, 0, n){
		cin >> a[i][j];
		if(!a[i][j]){
			x = i;
			y = j;
		}
	}
	if(n==1){
		cout << "1\n";
		return 0;
	}
	REP(i, 0, n) t_sum += a[i][y==0];
	miss = t_sum;
	REP(i, 0, n) miss -= a[i][y];
	a[x][y] = miss;
	if(miss&&chk_diagonals()&&chk_rows()&&chk_cols()) cout << a[x][y];
	else cout << -1;
	cout << "\n";
}

//18:40 01-06-2018
//18:42 01-06-2018
//18:43 01-06-2018
