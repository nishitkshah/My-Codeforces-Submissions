//09:16 18-07-2018
//09:42 18-07-2018

#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

void print_pairs(int n, int c){
	//print c pairs of sum (n+1)
	RE(i, 1, c+1)
		cout << ' ' << i << ' ' << n-i+1;
}

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	//cout << (((n%4==0) || ((n+1)%4==0)) ? 0 : 1);
	switch(n%4){
		case 0:
			cout << 0 << '\n' << n/2;
			print_pairs(n, n/4);
			break;
		case 1:
			cout << 1 << '\n' << n/2;
			cout << ' ' << (n+1)/2 << ' ' << n;
			print_pairs(n-1, n/4 - 1);
			break;
		case 2:
			cout << 1 << '\n' << n/2;
			cout << ' ' << n/2 + 1;
			print_pairs(n, n/4);
			break;
		case 3:
			cout << 0 << '\n' << n/2;
			cout << ' ' << n;
			print_pairs(n-1, n/4);
			break;
	}
	cout << '\n';
}

//09:58 18-07-2018
//10:01 18-07-2018
