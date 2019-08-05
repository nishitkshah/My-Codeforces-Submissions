//22:34 03-12-2018
//22:46 03-12-2018

#include<iostream>
#include<unordered_set>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100001

int n, a[N_], sum[N_]={0}, cnt[N_]={0}, mx;
unordered_set<int> s;

void rec(int v, int l=0){
if(!s.count(v)){
	sum[v] += l;
	cnt[v] += 1;
	s.insert(v);
}
int uv=v<<1, lv=v>>1;
if(uv<=mx)
	rec(uv, l+1);
rec(lv, l+1);
}

main(){
cin >> n;
mx = 0;
RE(i, 0, n){
	cin >> a[i];
	if(a[i]>mx) mx = a[i];
	s.clear();
	rec(a[i]);
}
int mn = N_;
RE(i, 0, N_)
	if(cnt[i]==n && sum[i]<mn)
		mn = sum[i];
cout << mn << '\n';
}

//23:02 03-12-2018
