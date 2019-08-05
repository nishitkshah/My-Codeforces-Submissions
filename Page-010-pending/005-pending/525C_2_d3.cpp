//15:22 07-08-2018
//15:32 07-08-2018 - 525C_1.cpp
//15:47 07-08-2018 - 525C_2.cpp
//16:03 07-08-2018
//16:10 07-08-2018
//16:50 09-08-2018

#include<iostream>
#include<algorithm>

using namespace std;

#define MAXN 100010

int n;
long long a[MAXN], dp[MAXN];

long long area(int p, int q){
	long long area=0LL,
	w=a[p-1], x=a[p], y=a[q], z=a[q+1];
	if((x-w)>1 || (z-y)>1)
		return 0LL;
	return w*y;
} 

main(){
	cin >> n;
	n+=3;
	a[0] = a[1] = a[2] = 0;
	for(int i=3; i<n; i++) cin >> a[i];
	sort(a, a+n);
	dp[0] = dp[1] = dp[2] = 0LL;
	int last_pair = 2;
	for(int i=3; i<(n-1); i++){
		dp[i] = max(dp[last_pair-2]+area(last_pair, i), dp[i-1]);
		if((a[i]-a[i-1])<=1){
			last_pair = i;
		}
	}
	cout << max(dp[n-3], dp[n-2]) << '\n';
}

//15:39 07-08-2018
//16:01 07-08-2018
//16:04 07-08-2018
//16:10 07-08-2018
//16:50 09-08-2018
//16:52 09-08-2018