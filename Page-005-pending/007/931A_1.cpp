//18:23 28-06-2018
//18:27 28-06-2018

#include<iostream>
#include<algorithm>

using namespace std;

main(){
	int a, b, p, q;
	cin >> a >> b;
	if(a>b) swap(a, b);
	b -= a;
	p = b/2; q = (b+1)/2;
	cout << (p*(p+1))/2 + (q*(q+1))/2 << "\n";
}

//18:30 28-06-2018
//18:31 28-06-2018
