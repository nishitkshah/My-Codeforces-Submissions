//21:20 18-02-2019
//21:24 18-02-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 200001

int n, m, a[N_], mx=0, mx2=0;
long long k, m1, m2, ans=0LL;

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> m >> k;
RE(i, 0, n){
	cin >> a[i];
	if(a[i]>=mx){
		mx2 = mx;
		mx = a[i];
	}else if(a[i]>mx2)
		mx2 = a[i];
}
m1 = (m+k-1)/k;
m2 = m/k;
cout << mx*m1 + mx2*m2 << '\n';
}

//21:30 18-02-2019