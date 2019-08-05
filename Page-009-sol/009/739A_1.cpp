//21:14 12-07-2018
//21:43 12-07-2018

#include<iostream>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define INF 10000000

int n, m, mn=INF, l, r;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	RE(i, 0, m){
		cin >> l >> r;
		mn = min(r-l+1, mn);
	}
	cout << mn << '\n';
	RE(i, 0, n){
		if(i) cout << ' ';
		cout << i%mn;
	}
	cout << '\n';
}

//21:47 12-07-2018
//21:48 12-07-2018
