//23:22 16-02-2019
//23:46 16-02-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 300001
#define A_ 2097152

int n, a[N_], o, e;
vector<int> v[A_];

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n;
a[0] = 0;
v[a[0]].push_back(0);
RE(i, 1, n+1){
	cin >> a[i];
	a[i] ^= a[i-1];
	v[a[i]].push_back(i);
}
long long ans = 0LL;
RE(i, 0, A_){
	o = 0, e = 0;
	for(auto ind: v[i]){
		if(ind%=2){
			ans += e;
			o++;
		}else{
			ans += o;
			e++;
		}
	}
}
cout << ans << '\n';
}

//23:53 16-02-2019
