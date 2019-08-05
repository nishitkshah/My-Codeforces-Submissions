//08:48 25-01-2019 to 09:06 25-01-2019
//19:03 25-01-2019
//22:48 25-01-2019
//23:06 25-01-2019
//23:19 25-01-2019

#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 10000
#define B1 100
#define B2 (B1*B1)

int n, T, r, a[N_], cnt[301]={0};
set<int> lis;

int conv(int v, int bi, int pi){
return v*B2+bi*B1+pi;
}

void calc_lis(){
lis.insert(a[0]);
RE(i, 1, n*r){
	auto it = lis.upper_bound(a[i]);
	if(it!=lis.end())
		lis.erase(it);
	lis.insert(a[i]);
}
}

main(){
cin >> n >> T;
r = min(n, T);
RE(i, 0, n){
	cin >> a[i];
	cnt[a[i]]++;
}
RE(i, 1, r)
	RE(j, 0, n)
		a[n*i+j] = a[j];
RE(i, 0, r)
	RE(j, 0, n)
		a[n*i+j] = conv(a[n*i+j], i, j);
calc_lis();
int mx = -1;
RE(i, 0, 301) mx = max(mx, cnt[i]);
cout << lis.size()+max(0, T-n)*mx;
}

//19:48 25-01-2019
//22:56 25-01-2019
//23:12 25-01-2019
//23:21 25-01-2019
//23:23 25-01-2019
