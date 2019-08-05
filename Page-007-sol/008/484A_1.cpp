//14:33 01-07-2018
//14:41 01-07-2018

#include<iostream>

using namespace std;

void solve(){
	long long a, b, x, ans=1LL;
	cin >> a >> b;
	x = a^b;
	while(x>1LL){
		x >> 1;
		ans << 1;
	}
	cout << l|(ans-1) << '\n';
}

main(){
	int n;
	for(int i=0; i<n; i++){
		solve();
	}
}

//14:46 01-07-2018
