//19:45 13-04-2019
//19:50 13-04-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 110

int n, m, h, a[N_], b[N_], c[N_][N_];

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> m >> h;
RE(i, 0, m) cin >> a[i];
RE(i, 0, n) cin >> b[i];
RE(i, 0, n){
	RE(j, 0, m){
		cin >> c[i][j];
		if(c[i][j])
			c[i][j] = min(a[j], b[i]);
		cout << c[i][j] << ' ';
	}
	cout << '\n';
}
}

//19:56 13-04-2019
//19:57 13-04-2019
