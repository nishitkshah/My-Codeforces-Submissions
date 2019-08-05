//23:37 18-10-2018
//23:58 18-10-2018
//00:16 19-10-2018
//00:24 19-10-2018
//00:26 19-10-2018

#include<iostream>
#include<unordered_map>
#include<cstdio>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 200000

int n, k, a[N_], msk, x[N_];
long long ans = 0LL;
unordered_map<int, int> m;

main(){
scanf("%d%d", &n, &k);
RE(i, 0, n) scanf("%d", &a[i]);
msk = (1<<k)-1;
x[0] = a[0];
m[x[0]] = m[x[0]]+1;
ans++;
RE(i, 1, n){
	int v[2]={a[i], msk^a[i]};
	int xr[2]={x[i-1]^v[0], x[i-1]^v[1]};
	int s[2] = {i+1-m[xr[0]], i+1-m[xr[1]]};
	int ind=0;
	if(s[0]<s[1]) ind = 1;
	x[i] = x[i-1]^v[ind];
	m[x[i]] = m[x[i]]+1;
	ans += s[ind];
}
printf("%d\n", ans);
}

//00:14 19-10-2018
//00:24 19-10-2018
//00:25 19-10-2018
//00:28 19-10-2018
//00:29 19-10-2018
