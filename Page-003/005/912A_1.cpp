//10:47 31-05-2018
//10:48 31-05-2018

#include<iostream>

using namespace std;

main(){
	int A, B, x, y, z, r1, r2, r;
	cin >> A >> B >> x >> y >> z;
	r1 = 2*x+y;
	r2 = y+3*z;
	r = A>r1 ? 0 : r1-A;
	r += B>r2 ? 0 : r2-B;
	cout << r << "\n";
}

//10:51 31-05-2018
