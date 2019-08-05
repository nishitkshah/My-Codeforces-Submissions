//14:33 01-07-2018
//14:41 01-07-2018
//14:47 01-07-2018
//14:49 01-07-2018
//14:54 01-07-2018

#include<iostream>

using namespace std;

void solve(){
	long long a, b, x, ans=1LL;
	cin >> a >> b;
	b++; //Needed as b can be the answer
	x = a^b;
	while(x>1LL){
		x = x >> 1;
		ans = ans << 1;
		//cerr << "Dbg: " << x << '\n';
	}
	cout << (a|(ans-1)) << '\n';
}

main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		solve();
	}
}

//14:46 01-07-2018
//14:48 01-07-2018
//14:54 01-07-2018
//14:55 01-07-2018
//14:56 01-07-2018
