//20:17 04-11-2018 to 20:47 04-11-2018
//22:24 05-11-2018
//22:32 05-11-2018

#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 5000

int n, a[N_][N_], q, l, r;

main(){
cin >> n;
RE(i, 0, n) cin >> a[0][i];
RE(i, 1, n)
	RE(j, 0, n-i)
		a[i][j] = a[i-1][j]^a[i-1][j+1];
/*
RE(i, 1, n){
	RE(j, 0, n-i)
		cerr << a[i][j] << ' ';
	cerr << '\n';
}
*/
RE(i, 1, n)
	RE(j, 0, n-i)
		a[i][j] = max(a[i][j], max(a[i-1][j], a[i-1][j+1]));
/*
RE(i, 1, n){
	RE(j, 0, n-i)
		cerr << a[i][j] << ' ';
	cerr << '\n';
}
*/
cin >> q;
RE(i, 0, q){
	cin >> l >> r;
	r = r-l;
	l--;
	cout << a[r][l] << '\n';
}
}

//22:30 05-11-2018
//22:36 05-11-2018
//22:39 05-11-2018
