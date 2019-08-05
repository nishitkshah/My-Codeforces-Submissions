//20:07 03-07-2018
//20:08 03-07-2018

#include<iostream>

using namespace std;

int n, a, c[101], mx=0;

main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a;
		c[a]++;
		if(mx<c[a]) mx = c[a];
	}
	cout << mx << '\n';
}

//20:10 03-07-2018
//20:11 03-07-2018
