//16:44 15-12-2018 - read editorial
//17:59 15-12-2018

#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

int d[] = {1, 2, 3, 5};

main(){
int n, k;
cin >> n >> k;
cout << k*(6*n-1) << '\n';	//ie: k*(6*(n-1) + 5)
RE(i, 0, n){
	RE(j, 0, 4){
		if(j) cout << ' ';
		cout << k*6*i+d[j];
	}
	cout << '\n';
}
}

//18:03 15-12-2018
