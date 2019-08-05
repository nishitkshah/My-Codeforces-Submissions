//19:33 28-06-2018
//19:39 28-06-2018

#include<iostream>
#include<algorithm>

using namespace std;

const int mx = 1000000;
const int mid = mx/2;

main(){
	int n, a, l=1, r=mx;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a;
		if(a<=mid) l = max(l, a);
		else r = min(r, a);
	}
	cout << max(l-1, mx-r) << "\n";
}

//19:44 28-06-2018
//19:44 28-06-2018
