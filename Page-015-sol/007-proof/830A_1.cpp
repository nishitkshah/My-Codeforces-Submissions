//15:17 01-11-2018
//16:00 01-11-2018

#include<iostream>
#include<algorithm>
#include<cstdlib>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 1000
#define E 1000000001

int n, k, p, a[N_], b[2*N_];

long long mxtime(int s){
long long ans = 0LL;
RE(i, 0, n)
	ans = max(ans, abs(b[i+s]-a[i])+abs(b[i+s]-p));
return ans;
}

main(){
cin >> n >> k >> p;
RE(i, 0, n) cin >> a[i];
RE(i, 0, k) cin >> b[i];
sort(a, a+n);
sort(b, b+k);
long long ans = 0LL;
RE(i, 0, k-n+1)
	ans = max(ans, mxtime(i));
cout << ans << '\n';
}

//16:11 01-11-2018
