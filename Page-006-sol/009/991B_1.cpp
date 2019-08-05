//09:11 29-06-2018
//09:17 29-06-2018

#include<iostream>
#include<algorithm>

using namespace std;

main(){
	int n, a[100], s=0, mn=0, c=0;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
		s += a[i];
	}
	mn = 5*((n+1)/2) + 4*(n/2);
	if(s<mn){
		sort(a, a+n);
		for(int i=0; (s<mn)&&(i<n); i++){
			s = s-a[i]+5;
			c++;
		}
	}
	cout << c << '\n';
}

//09:24 29-06-2018
//09:26 29-06-2018
