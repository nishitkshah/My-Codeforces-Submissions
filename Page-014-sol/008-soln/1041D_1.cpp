//17:38 21-10-2018
//17:50 21-10-2018

#include<iostream>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 200000
#define TENp9 1000000000

int n, h, d[N_+1], s[N_+1];

main(){
cin >> n >> h;
int p=-TENp9, x, y;
s[0] = 0;
RE(i, 0, n){
	cin >> x >> y;
	d[i] = x-p;
	s[i+1] = y-x;
	p = y;
}
d[n] = TENp9-y;
int ans=0, l=0, r=0, dsum=d[0], ssum=s[0];
RE(i, 0, n+1){
	while(r<n && dsum<h){
		r++;
		dsum += d[r];
		ssum += s[r];
	}
	ans = max(ssum, ans);
	dsum -= d[l];
	ssum -= s[l];
	l++;
	if(r<l){
		r = l;
		dsum += d[r];
		ssum += s[r];
	}
}
cout << ans+h << '\n';
}

//18:08 21-10-2018
//18:14 21-10-2018
