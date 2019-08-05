#include<iostream>
#include<algorithm>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)
#define dREP(a, b, c) for(int a=(b); a>=(c); a--)
#define MAX 200001

long long n, a[MAX], dp[MAX], mn, mni;

int main(){
	ios::sync_with_stdio(0);
	cin >> n;
	mn = 1000000001, mni=-1;
	REP(i, 0, n){
		cin >> a[i];
		if(mn>a[i]){
			mn = a[i];
			mni = i;
		}
	}
	long long mx = -1;
	dREP(i, n-1, 0){
		if(a[i]==mn)
			mni = i;
		dp[i] = mni-i;
		if(dp[i]<0) dp[i] += n;
		dp[i] += mn*n;
		mx = max(mx, dp[i]);
	}
	cout << mx;
	return 0;
}
