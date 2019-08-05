//10:38 31-05-2018
//10:42 31-05-2018

#include<iostream>
#include<algorithm>

using namespace std;

main(){
	int n, k, a, mn=1000;
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> a;
		if(!(k%a)){
			mn = min(k/a, mn);
		}
	}
	cout << mn << "\n";
}

//10:45 31-05-2018
//10:46 31-05-2018
