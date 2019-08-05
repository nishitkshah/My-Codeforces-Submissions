//21:00 08-03-2019
//21:11 08-03-2019
//21:26 08-03-2019 - would fail because of integer overflow (ans cannot be in long long)

#include<iostream>
#include<unordered_map>

using namespace std;

typedef long long lli;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 200001

int n;
lli a[N_], sm=0LL, ans=0LL;
unordered_map<lli, lli> mp;

main(){
cin >> n;
RE(i, 0, n) cin >> a[i];
RE(i, 0, n){
	ans += i*a[i]-sm;
	if(mp.count(a[i]-1))
		ans -= mp[a[i]-1];
	if(mp.count(a[i]+1))
		ans += mp[a[i]+1];
	if(mp.count(a[i]))
		mp[a[i]]++;
	else
		mp[a[i]] = 1LL;
	sm += a[i];
}
cout << ans << '\n';
}

//21:25 08-03-2019
//21:26 08-03-2019
//21:38 08-03-2019
