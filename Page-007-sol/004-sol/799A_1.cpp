//20:47 29-06-2018
//20:53 29-06-2018

#include<iostream>

using namespace std;

main(){
	int n, t, k, d;
	cin >> n >> t >> k >> d;
	int c = ((d+t)/t)*k;
	if(c<n) cout << "YES\n";
	else cout << "NO\n";
}

//20:57 29-06-2018
//20:58 29-06-2018
