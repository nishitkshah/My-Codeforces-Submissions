//19:54 03-07-2018
//19:56 03-07-2018

#include<iostream>
#include<algorithm>

using namespace std;

int k, n, c[100], d, t;

main(){
	cin >> k >> n;
	for(int i=0; i<n; i++){
		cin >> t;
		t--;
		c[t]++;
	}
	d = n/k;
	int ans = 0;
	for(int i=0; i<k; i++) ans += max(c[i]-d, 0);
	cout << ans << '\n';
}

//20:01 03-07-2018
