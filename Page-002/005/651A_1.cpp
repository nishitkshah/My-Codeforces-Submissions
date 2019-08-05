//11:23 30-05-2018
//11:28 30-05-2018

#include<iostream>
#include<algorithm>

using namespace std;

main(){
	int a, b, mx, mn, t=0;
	cin >> a >> b;
	while(a>0&&b>0){
		mx = max(a, b)-2;
		mn = min(a, b)+1;
		a = mx; b = mn;
		t++;
	}
	cout << t << "\n";
}

//11:32 30-05-2018
