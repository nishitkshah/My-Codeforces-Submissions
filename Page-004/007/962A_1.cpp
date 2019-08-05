//17:25 01-06-2018
//17:27 01-06-2018

#include<iostream>

using namespace std;

main(){
	int n, a[200000];
	long long sum=0, half=0;

	cin >> n;

	for(int i=0; i<n; i++){
		cin >> a[i];
		sum += a[i];
	}
	for(int i=0; i<n; i++){
		half += a[i];
		if(2*half>=sum){
			cout << i+1 << "\n";
			break;
		}
	}
}

//17:30 01-06-2018
//17:32 01-06-2018
