//21:11 13-02-2019 - read editorial
//21:34 13-02-2019

#include<iostream>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100000
#define P9 1000000000

int n, m, a[N_], b[N_], k;

int b_search(){
int l=n, h=P9+N_+1, m;
while(l!=(h-1)){
	m = l+(h-l)/2;
	RE(i, 0, n) b[i] = a[i];
	int t=n, c;
	RE(i, 0, m){
		c = m;
		while(t && !a[t-1]) t--;
		c -= t;
		while(c && t){
			int d = min(c, a[t-1]);
			c -= d;
			a[t-1] -= d;
			if(!a[t-1]) t--;
		}
		while(t && !a[t-1]) t--;
	}
	if(t) l = m;
	else h = m;
}
return h;
}

main(){
cin >> n >> m;
RE(i, 0, n) cin >> a[i];
cout << b_search() << '\n';
}

//21:54 13-02-2019
