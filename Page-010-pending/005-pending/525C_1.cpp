//15:22 07-08-2018
//15:32 07-08-2018

#include<iostream>
#include<algorithm>

using namespace std;

#define MAXN 100010

int n;
long long a[MAXN], dp[MAXN];

long long area(int i){
	if(i<3) return 0LL;
	long long area=0LL, w=a[i-3], x=a[i-2], y=a[i-1], z=a[i];
	if((x-w)>1 || (z-y)>1)
		return 0LL;
	return w*y;
} 

main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	dp[0] = dp[1] = dp[2] = 0LL;
	dp[3] = area(3);
	for(int i=4; i<n; i++)
		dp[i] = max(dp[i-4]+area(i), dp[i-1]);
	cout << dp[n-1] << '\n';
}

//15:39 07-08-2018
