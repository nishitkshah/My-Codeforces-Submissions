//14:03 01-07-2018
//14:15 01-07-2018

#include<iostream>

using namespace std;

void display_1(int a){
	cout << a+1 << " - " << a << " = 1\n";
	cout << "24 * 1 = 24\n";
}

void display_24(int a){
	if(a%2==0){
		cout << "4 * 3 = " << 4*3 << '\n';
		cout << "2 * 1 = " << 2 << '\n';
		cout << "12 * 2 = " << 24 << '\n';
	}else{
		cout << "5 * 4 = " << 5*4 << '\n';
		cout << "3 - 1 = " << 3-1 << '\n';
		cout << "2 * 2 = " << 4 << '\n';
		cout << "20 + 4 = " << 24 << '\n';
	}
}

main(){
	int n, next;
	cin >> n;
	if(n<4){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	display_24(n);
	next = n%2 ? 6 : 5;
	while(next<n){
		display_1(next);
		next += 2;
	}
}

//14:25 01-07-2018
//14:27 01-07-2018
