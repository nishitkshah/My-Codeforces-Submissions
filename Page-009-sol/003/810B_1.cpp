//19:01 03-07-2018
//19:05 03-07-2018

#include<iostream>
#include<algorithm>

using namespace std;

#define MAX 100000

main(){
	int n, f, k, l, d[MAX];
	long long ans = 0LL;
	cin >> n >> f;
	for(int i=0; i<n; i++){
		cin >> k >> l;
		ans += min(k, l);
		d[i] = min(k, max(l-k, 0));
	}
	sort(d, d+n);
	for(int i=0; i<f; i++) ans += d[n-1-i];
	cout << ans << '\n';
}

//19:11 03-07-2018
//19:13 03-07-2018
