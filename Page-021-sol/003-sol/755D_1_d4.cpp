//22:42 08-03-2019 - read editorial
//23:30 08-03-2019
//23:59 08-03-2019
//00:03 09-03-2019
//00:11 09-03-2019
//00:21 09-03-2019

#include<iostream>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 1000001

int n, k, st[8*N_]={0};
long long r=1LL;

void insert(int x, int v=1, int ind=0, int l=0, int r=2*N_){
if(l==(r-1)){
	st[ind] += v;
	return;
}
int m = l+(r-l)/2;
if(x<m) insert(x, v, 2*ind+1, l, m);
else insert(x, v, 2*ind+2, m, r);
st[ind] += v;
}

int query(int x, int y, int ind=0, int l=0, int r=2*N_){
if(x<=l && (r-1)<=y)
	return st[ind];
int m = l+(r-l)/2;
if(y<m) return query(x, y, 2*ind+1, l, m);
if(x>=m) return query(x, y, 2*ind+2, m, r);
return query(x, m-1, 2*ind+1, l, m)+query(m, y, 2*ind+2, m, r);
}

main(){
cin >> n >> k;
k = min(k, n-k);
int x = 0;
RE(i, 0, n){
	long long nr = 1;
	insert(x);
	insert(x+k);
	insert(x+n);
	if((x+k+n)<2*n) insert(x+k+n);
	else insert((x+k)%n);
	nr += query(x+1, x+k-1);
	r += nr;
	if(i) cout << ' ';
	cout << r;
	x += k;
	x %= n;
}
cout << '\n';
}

//23:58 08-03-2019
//00:01 09-03-2019
//00:04 09-03-2019
//00:11 09-03-2019
//00:28 09-03-2019
//00:29 09-03-2019
