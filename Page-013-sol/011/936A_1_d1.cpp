//23:04 17-10-2018
//23:18 17-10-2018
//23:33 17-10-2018

#include<iostream>

using namespace std;

main(){
	long long k, d, t1, t, h, c;
	long double tm;
	cin >> k >> d >> t1;
	d = ((k+d-1)/d)*d;
	h = 2*k;
	c = d-k;
	t = 2*t1;
	long long m = t/(h+c);
	t = t%(h+c);
	tm = ((long double)m)*d;
	if(t<=h){
		tm += t/2.0;
	}else{
		tm += h/2;
		tm += (t-h);
	}
	cout << tm << '\n';
}

//23:32 17-10-2018
//23:34 17-10-2018
//23:34 17-10-2018
