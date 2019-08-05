//19:55 13-03-2019
//20:04 13-03-2019
//20:14 13-03-2019

#include<iostream>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100000
#define INF 1000000000000000001LL

int n, a[N_], b[N_];
long long ans=INF, x, y, p, q;

main(){
cin >> n;
RE(i, 0, n) cin >> a[i];
RE(i, 0, n) cin >> b[i];
x = b[0], q = a[n-1];
ans = x*q;
if(n==1) ans = 0LL;
RE(i, 1, n){
	y = b[i], p = a[i];
	ans = min(ans, x*p+y*q);
}
cout << ans << '\n';
}

//20:11 13-03-2019
//20:14 13-03-2019
//20:14 13-03-2019
