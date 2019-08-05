//23:13 03-09-2018
//23:15 03-09-2018

#include<iostream>
#include<unordered_set>
#include<cmath>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

#define MAXN 100000
const long long MAX = 1000000000000000LL;

int n, k, a[100000];
long long sum=0LL, pow = 1LL, ans=0LL;

main(){
	cin >> n >> k;
	RE(i, 0, n) cin >> a[i];
	while(abs(pow)<=MAX){
		sum = 0LL;
		unordered_set<long long> st;
		RE(i, 0, n){
			sum += a[i];
			if(st.count(sum-pow)) ans++;
			st.insert(sum);
		}
		pow = pow*k;
	}
	cout << ans << '\n';
}

//23:26 03-09-2018
