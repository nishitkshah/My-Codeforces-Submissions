//09:47 31-05-2018 to 09:52 31-05-2018
//10:22 31-05-2018

#include<iostream>

using namespace std;

main(){
	int m, n;
	cin >> m >> n;
	if(n==1) cout << 1;
	else if( m > ((n+1)/2) ) cout << m-1;
	else cout << m+1;
	cout << "\n";
}

//10:24 31-05-2018
