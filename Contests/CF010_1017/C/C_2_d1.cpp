//20:33 08-08-2018
//20:43 08-08-2018
//20:52 08-08-2018
//20:58 08-08-2018 - C_2.cpp
//21:05 08-08-2018

#include<iostream>
#include<algorithm>

using namespace std;

main(){
	int n, k, mn;
	cin >> n;
	mn = n+1;
	k = 1;
	for(int i=1; i<=n; i++){
		int sm = i + ((n+i-1)/i);
		//cerr << "Dbg: " << i << " " << sm << endl;
		if(sm<mn){
			mn = sm;
			k = i;
		}
	}
	//cerr << "Dbg: " << k << endl;
	for(int i=1; i<=n; i+=k){
		int lst = min(i+k-1, n);
		for(int j=lst; j>=i; j--){
			if(j!=k) cout << ' ';
			cout << j;
		}
	}
	cout << '\n';
}

//20:48 08-08-2018
//20:53 08-08-2018
//21:04 08-08-2018
//21:09 08-08-2018
//21:10 08-08-2018
