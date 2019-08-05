//22:40 11-06-2019 to 22:45 11-06-2019
//00:24 20-06-2019
//00:53 20-06-2019
//01:17 20-06-2019

#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ (2001*100)
#define D_ 11
#define MX (1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL)

int n, k, subc=0, l[N_]={0}, dp[N_][D_]={0};
long long a[N_], ans=0LL;
unordered_map<int, int> rl[D_];

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> k;
RE(i, 0, n) cin >> a[i];
RE(i, 0, n){
	long long p = 1LL;
	l[i] = 0;
	while(p<=a[i])
		l[i]++, p *= 10;
	int sm_pr = ((p%k) * (a[i]%k))%k;
	sm_pr = (sm_pr+a[i])%k;
	if(sm_pr==0)
		subc++;
}
RE(i, 0, n){
	long long cv = a[i]%k;
	RE(j, 0, D_){
		if(rl[j].count(cv%k))
			rl[j][cv%k]++;
		else
			rl[j][cv%k] = 1;
		//if(cv>=MX) break;
		cv = (cv*10)%k;
	}
}
RE(i, 0, n)
	if( rl[l[i]].count( (k - (a[i]%k)) % k) )
		ans += rl[l[i]][(k-(a[i]%k))%k];
ans -= subc;
cout << ans << '\n';
}

//00:46 20-06-2019
//01:11 20-06-2019
//01:20 20-06-2019
//01:20 20-06-2019
