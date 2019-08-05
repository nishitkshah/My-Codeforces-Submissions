//20:33 08-08-2018
//20:43 08-08-2018
//20:52 08-08-2018
//20:58 08-08-2018 - C_2.cpp

#include<iostream>
#include<algorithm>

using namespace std;

main(){
	int n, k, mx;
	cin >> n;
	mx = n+1;
	k = 1;
	for(int i=1; i<n; i+=2){
		int sm = i + ((n+i-1)/i);
		if(sm<mx){
			mx = sm;
			k = i;
		}
	}
	for(int i=1; i<n; i+=k){
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
