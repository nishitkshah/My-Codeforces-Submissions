//18:53 16-08-2018
//19:04 16-08-2018

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAX 300000
#define MOD 1000000007

int n;
vector<int> v;
long long ans=0LL;

main(){
	cin >> n;
	v.resize(n);
	RE(i, 0, n) cin >> v[i];
	if(n==1){
		cout << "0\n";
		return 0;
	}
	sort(v.begin(), v.end());
	int l=n-1;
	long long sum=0LL, diffp=0LL;
	while(l){
		sum *= 2;
		sum += v[l];
		sum %= MOD;
		diffp *= 2;
		diffp += 1;
		diffp %= MOD;
		ans += sum-(diffp*v[l-1]);
		ans = ( MOD + (ans%MOD) ) % MOD;
		l--;
	}
	cout << ans << '\n';
}

//19:20 16-08-2018
//19:25 16-08-2018
