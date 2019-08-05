//22:07 28-06-2018
//22:10 28-06-2018

#include<iostream>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

main(){
	int p, n, x;
	int h[300];
	cin >> p >> n;
	REP(i, 0, p) h[i] = -1;
	REP(i, 0, n){
		cin >> x;
		if(h[x%p]!=-1){
			cout << i+1 << "\n";
			return 0;
		}
		h[x%p] = x;
	}
	cout << "-1\n";
}

//22:13 28-06-2018
//22:15 28-06-2018
