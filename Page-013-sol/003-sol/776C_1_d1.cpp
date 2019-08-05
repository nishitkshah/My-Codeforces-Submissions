//23:13 03-09-2018
//23:15 03-09-2018
//23:27 03-09-2018

#include<iostream>
#include<unordered_set>
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
		unordered_set<long long> st;
		RE(i, 0, n){
			sum += a[i];
			if(st.count(sum-pw)) ans++;
			st.insert(sum);
		}
		pw *= k;
	}
	cout << ans << '\n';
}

//23:26 03-09-2018
//23:28 03-09-2018
