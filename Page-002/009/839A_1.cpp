//14:30 30-05-2018
//14:35 30-05-2018

#include<iostream>
#include<algorithm>

using namespace std;

main(){
	int n, k, a, store=0, d, t;
	cin >> n >> k;
	for(int d=1; d<=n; d++){
		cin >> a;
		store += a;
		t = min(store, 8);
		k -= t;
		store -= t;
		if(k<=0) break;
	}
	if(k>0) d = -1;
	cout << d << "\n";
}

//14:41 30-05-2018
