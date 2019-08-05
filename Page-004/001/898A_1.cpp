//12:04 31-05-2018
//12:05 31-05-2018

#include<iostream>

using namespace std;

main(){
	int n, d;
	cin >> n;
	d = n%10;
	n -= d;
	if(d>5) n+=10;
	cout << n << "\n";
}

//12:07 31-05-2018
//12:08 31-05-2018
