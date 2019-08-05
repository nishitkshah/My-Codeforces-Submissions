//19:00 13-08-2018
//19:07 13-08-2018
//19:14 13-08-2018

#include<iostream>

using namespace std;

#define MAX 200000
#define RE(a, b, c) for(int a=(b); a<(c); a++)

main(){
	int n, q, p;
	long long a[MAX], k, sum=0LL;
	cin >> n >> q;
	RE(i, 0, n){
		cin >> a[i];
		if(i) a[i] += a[i-1];
	}
	p = 0;
	RE(i, 0, q){
		cin >> k;
		sum += k;
		//cerr << "Dbg: " << sum << ' ' << a[i] << '\n';
		while(p<n && sum>=a[p])
			p++;
		//cerr << "Dbg: " << p << '\n';
		if(p==n){
			p = 0;
			sum = 0LL;
		}
		cout << n-p << '\n';
	}
}

//19:13 13-08-2018
//19:20 13-08-2018
//19:21 13-08-2018
