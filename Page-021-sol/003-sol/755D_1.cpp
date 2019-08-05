//22:42 08-03-2019 - read editorial
//23:30 08-03-2019

#include<iostream>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 1000001

int n, k, st[8*N_]={0}, r=1;

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
RE(i, 0, n){
	int nr = 1;
	insert(i);
	insert(i+k);
	insert(i+n);
	if((i+k+n)<2*n) insert(i+k+n);
	nr += 2*query(i+1, i+k-1);
	r += nr;
	if(i) cout << ' ';
	cout << r;
}
cout << '\n';
}

//23:58 08-03-2019
