//10:55 31-05-2018
//10:58 31-05-2018

#include<iostream>
#include<algorithm>

using namespace std;

main(){
	int n, h[100010], dp[100010], mx;
	cin >> n;
	for(int i=0; i<n; i++) cin >> h[i];
	mx = h[n-1]-1;
	for(int i=n-1; i>=0; i--){
		dp[i] = max(h[i], mx+1);
		mx = max(mx, h[i]);
	}
	cout << dp[0]-h[0];
	for(int i=1; i<n; i++) cout << " " << dp[i]-h[i];
	cout << "\n";
}

//11:03 31-05-2018
//11:04 31-05-2018
