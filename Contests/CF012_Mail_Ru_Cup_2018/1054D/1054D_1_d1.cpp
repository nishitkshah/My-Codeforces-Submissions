//23:37 18-10-2018
//23:58 18-10-2018
//00:16 19-10-2018

#include<iostream>
#include<set>
#include<cstdio>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 200000

int n, k, a[N_], msk, x[N_];
long long ans = 0LL;
multiset<int> m;

main(){
scanf("%d%d", &n, &k);
RE(i, 0, n) scanf("%d", &a[i]);
msk = (1<<k)-1;
x[0] = a[0];
m.insert(x[0]);
ans++;
cerr << "Mask:" << msk << "\n";
cerr << "DBG INV:\n";
cerr << a[0];
RE(i, 1, n){
	int v[2]={a[i], msk^a[i]};
	int xr[2]={x[i-1]^v[0], x[i-1]^v[1]};
	int s[2] = {i+1-m.count(xr[0]), i+1-m.count(xr[1])};
	int ind=0;
	if(s[0]<s[1]) ind = 1;
	x[i] = x[i-1]^v[ind];
	cerr << " " << v[ind];
	m.insert(x[i]);
	ans += s[ind];
}
cerr << '\n';
cerr << "DBG XOR:\n";
RE(i, 0, n) cerr << x[i] << ' '; cerr << '\n';
printf("%d\n", ans);
}

//00:14 19-10-2018
//00:24 19-10-2018
