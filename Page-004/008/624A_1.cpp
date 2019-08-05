//17:32 01-06-2018
//17:34 01-06-2018

#include<iostream>

using namespace std;

main(){
	int d, L, v1, v2;
	cin >> d >> L >> v1 >> v2;
	v1 += v2;
	L -= d;
	long double t = L;
	t = t/v1;
	printf("%.9Lf\n", t);
}

//17:38 01-06-2018
//17:40 01-06-2018
