//22:56 05-11-2018 to 23:00 05-11-2018 and 17:18 06-11-2018 to 17:53 06-11-2018 - read editorial
//22:13 06-11-2018

#include<iostream>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 200000
#define L_ 894
#define MOD 1000000007

int r, g, l, dp[N_+1][L_]={0};

inline int tri(int l){
	return (l*(l+1))/2;
}

main(){
cin >> r >> g;
l = 1;
while( tri(l) <= (r+g) ) l++;
l--;
dp[0][0] = 1;
RE(li, 1, l+1){
	RE(rc, 0, r+1){
		int gc = tri(li)-rc;
		if(li<=rc && rc<=min(tri(li), r) && gc<=min(tri(li), g))
			dp[rc][li] += dp[rc-li][li-1], dp[rc][li] %= MOD;
		if(li<=gc && gc<=min(tri(li), g) && rc<=min(tri(li), r))
			dp[rc][li] += dp[rc][li-1], dp[rc][li] %= MOD;
	}
}
int ans=0;
RE(i, 0, r+1) ans += dp[i][l], ans %= MOD;
cout << ans << '\n';
}

//22:41 06-11-2018
//22:43 06-11-2018