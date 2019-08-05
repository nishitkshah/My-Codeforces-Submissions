//08:48 25-01-2019 to 09:06 25-01-2019
//19:03 25-01-2019

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
RE(i, 1, r)
	RE(j, 0, n)
		a[n*i+j] = conv(a[n*i+j], i, j);
calc_lis();
int sz=lis.size(), ev=-1, ans=0;
if(T<=n){
	cout << sz << '\n';
	return 0;
}
while(lis.size()){
	auto it = lis.end();
	it--;
	if(((*it)/B2) != (ev/B2)){
		int val, blk, blke, rem;
		val = (*it)/B2;
		blk = ((*it)/B1)%B2;
		if(ev!=-1)
			blke = (r-1)-(ev/B1)%B2;
		else
			blke = 0;
		rem = T-(blk+1)-blke;	//blk: 0-indexed
		ans = max(ans, sz+rem*cnt[val]);	//choosing the tail of lis in the end blocks is always beneficial
	}
	ev = *it;
	lis.erase(it);
}
cout << ans << '\n';
}

//19:48 25-01-2019
