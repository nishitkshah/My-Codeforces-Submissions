//10:13 30-05-2018
//10:16 30-05-2018

#include<iostream>

using namespace std;

main(){
	int n, d, s=0, t;
	cin >> n >> d;
	for(int i=0; i<n; i++){
		cin >> t;
		s += t;
	}
	d -= s;
	if(d>=(10*(n-1))) cout << d/5 << "\n";
	else cout << "-1\n";
}

//10:20 30-05-2018
//10:21 30-05-2018
