//21:11 13-02-2019 - read editorial
//21:34 13-02-2019
//21:58 13-02-2019
//22:07 13-02-2019
//22:12 13-02-2019
//23:20 13-02-2019

#include<iostream>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100000
#define P9 1000000000LL

int n, m, a[N_], b[N_];

long long b_search(){
long long l=0LL, h=(N_*P9)+N_+1LL, ml;
while(l!=(h-1)){
	ml = l+(h-l)/2;
	RE(i, 0, n) b[i] = a[i];
	int t=n;
	long long c;
	RE(i, 0, m){
		c = ml;
		while(t && !b[t-1]) t--;
		c -= t;
		while(c>0 && t){
			long long d = min(c, (long long)b[t-1]);
			c -= d;
			b[t-1] -= d;
			if(!b[t-1]) t--;
		}
		while(t && !b[t-1]) t--;
	}
	if(t) l = ml;
	else h = ml;
}
return h;
}

main(){
cin >> n >> m;
RE(i, 0, n) cin >> a[i];
cout << b_search() << '\n';
}

//21:54 13-02-2019
//22:04 13-02-2019
//22:07 13-02-2019
//22:15 13-02-2019
//23:20 13-02-2019
//23:21 13-02-2019
