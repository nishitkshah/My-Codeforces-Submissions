//21:04 21-09-2018
//21:16 21-09-2018
//21:27 21-09-2018

#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

main(){
	int n, a=0, ai, m, l, r, ans=-1;
	cin >> n;
	RE(i, 0, n){
		cin >> ai;
		a += ai;
	}
	cin >> m;
	RE(i, 0, m){
		cin >> l >> r;
		if(a<=r){
			if(a<l)	ans = l;
			else ans = a;
			break;
		}
	}
	cout << ans << '\n';
}

//21:21 21-09-2018
//21:28 21-09-2018
//21:29 21-09-2018
