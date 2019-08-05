//23:13 03-09-2018
//23:15 03-09-2018
//23:27 03-09-2018
//23:29 03-09-2018
//23:38 03-09-2018

#include<iostream>
#include<unordered_map>
#include<cmath>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

#define MAXN 100000
const long long MAX = 1000000000000000LL;

int n, k, a[100000];
long long sum=0LL, pw=1LL, ans=0LL;

main(){
	cin >> n >> k;
	RE(i, 0, n) cin >> a[i];
	while(abs(pw)<=MAX){
		sum = 0LL;
		unordered_map<long long, int> mp;
		RE(i, 0, n){
			mp[sum]++;
			sum += a[i];
			ans += mp[sum-pw];
		}
		pw *= k;
		if(pw==((long long)k)) break;	//For 1 and -1
	}
	cout << ans << '\n';
}

//23:26 03-09-2018
//23:28 03-09-2018
//23:30 03-09-2018
//23:44 03-09-2018
//23:46 03-09-2018
