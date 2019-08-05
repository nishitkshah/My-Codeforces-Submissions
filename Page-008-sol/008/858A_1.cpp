//22:20 02-07-2018
//22:22 02-07-2018

#include<iostream>

using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k, nm, p=1;
	cin >> n >> k;
	nm = n;
	while(k&&(nm%10==0)) nm /= 10, k--;
	if(k){
		while(k&&(nm%2==0)){
			nm /= 2;
			k--;
			p *= 5;
		}
		while(k&&(nm%5==0)){
			nm /= 5;
			k--;
			p *= 2;
		}
		while(k){
			k--;
			p *= 10;
		}
	}
	cout << n*p << '\n';
}

//22:28 02-07-2018
