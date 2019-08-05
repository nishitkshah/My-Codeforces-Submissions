//19:54 03-07-2018
//19:56 03-07-2018
//20:02 03-07-2018

#include<iostream>
#include<algorithm>

using namespace std;

int k, n, c[100], d, t;

main(){
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> t;
		t--;
		c[t]++;
	}
	d = n/k;
	int ans = 0;
	//cerr << d << endl;
	//for(int i=0; i<k; i++) cerr << c[i] << endl;
	for(int i=0; i<k; i++) ans += max(c[i]-d, 0);
	cout << ans << '\n';
}

//20:01 03-07-2018
//20:05 03-07-2018
//20:05 03-07-2018
