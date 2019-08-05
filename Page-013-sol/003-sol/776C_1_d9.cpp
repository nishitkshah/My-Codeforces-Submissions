//23:13 03-09-2018
//23:15 03-09-2018
//23:27 03-09-2018
//23:29 03-09-2018
//23:38 03-09-2018
//23:48 03-09-2018
//23:53 03-09-2018
//21:40 04-09-2018
//21:44 04-09-2018
//22:20 04-09-2018
//23:24 04-09-2018

#include<iostream>
#include<unordered_map>
#include<cmath>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

#define MAXN 100000
const long long MAX = 1000000000000000LL;
//const int modif = 13; //Modifies the input number to map so as to prevent hash collision

int n, k, a[100000];
long long sum=0LL, pw=1LL, ans=0LL;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	RE(i, 0, n) cin >> a[i];
	while(abs(pw)<=MAX){
		sum = 0LL;
		unordered_map<long long, int> mp;
		mp.reserve(16384);
		mp.max_load_factor(0.25);
		RE(i, 0, n){
			mp[sum]++;
			sum += a[i];
			ans += mp[sum-pw];
		}
		pw *= k;
		if(pw==1LL) break;	//When k is 1 or -1
	}
	cout << ans << '\n';
}

//23:26 03-09-2018
//23:28 03-09-2018
//23:30 03-09-2018
//23:44 03-09-2018
//23:50 03-09-2018
//23:54 03-09-2018
//21:42 04-09-2018
//21:45 04-09-2018
//22:27 04-09-2018
//23:25 04-09-2018
//23:25 04-09-2018
