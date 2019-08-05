//10:35 14-08-2018
//10:42 14-08-2018
//11:12 14-08-2018

#include<iostream>

using namespace std;

main(){
	int n;
	cin >> n;
	cout << 2*(n/2) + (n+1)/2 << '\n';
	for(int i=2; i<(n+1); i+=2){
		if(i!=2) cout << ' ';
		cout << i;
	}
	for(int i=1; i<(n+1); i+=2){
		cout << ' ' << i;
	}
	for(int i=2; i<(n+1); i+=2){
		cout << ' ' << i;
	}
}

//10:53 14-08-2018
//11:20 14-08-2018
//11:21 14-08-2018
