//17:09 16-05-2018
//17:10 16-05-2018
//17:15 16-05-2018

#include<iostream>
#include<algorithm>

using namespace std;

int a[100001], n, dp[100001], mx;

int main(){
	cin >> n;
	dp[0] = 1;
	mx = 1;
	cin >> a[0];
	for(int i=1; i<n; i++){
		cin >> a[i];
		if(a[i]>=a[i-1]) dp[i] = dp[i-1]+1;
		else dp[i] = 1;
		mx = max(mx, dp[i]);
	}
	cout << mx << "\n";
	return 0;
}

//17:14 16-05-2018
//17:16 16-05-2018
//17:17 16-05-2018 - submitted
