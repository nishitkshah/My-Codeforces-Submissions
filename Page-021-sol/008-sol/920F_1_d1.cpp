//11:12 16-03-2019
//11:35 16-03-2019
//12:15 16-03-2019

#include<iostream>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 300001
#define A_ 1000001

int n, m, t, l, r, a[N_], d[A_]={0}, mx[4*N_]={0};
long long sm[4*N_]={0};

void update(int x, int y, int ind=0, int l=0, int r=N_){
//cerr << ind << ' ' << l << ' ' << r << '\n';
if(mx[ind]<=2) return;
if(l==(r-1)){
	sm[ind] = d[(int)sm[ind]];
	mx[ind] = sm[ind];
	return;
}
int m = l+(r-l)/2;
if(y<m){
	update(x, y, 2*ind+1, l, m);
	sm[ind] = sm[2*ind+1]+sm[2*ind+2];
	mx[ind] = max(mx[2*ind+1], mx[2*ind+2]);
}else if(x>=m){
	update(x, y, 2*ind+2, m, r);
	sm[ind] = sm[2*ind+1]+sm[2*ind+2];
	mx[ind] = max(mx[2*ind+1], mx[2*ind+2]);
}else{
	update(x, m-1, 2*ind+1, l, m);
	update(m, y, 2*ind+2, m, r);
	sm[ind] = sm[2*ind+1]+sm[2*ind+2];
	mx[ind] = max(mx[2*ind+1], mx[2*ind+2]);
}
}

long long query(int x, int y, int ind=0, int l=0, int r=N_){
//cerr << ind << ' ' << l << ' ' << r << '\n';
if(x==l && y==(r-1))
	return sm[ind];
int m = l+(r-l)/2;
if(y<m)
	return query(x, y, 2*ind+1, l, m);
else if(x>=m)
	return query(x, y, 2*ind+2, m, r);
else
	return query(x, m-1, 2*ind+1, l, m) + query(m, y, 2*ind+2, m, r);
}

void build(int ind=0, int l=0, int r=N_){
//cerr << ind << ' ' << l << ' ' << r << '\n';
if(l==(r-1)){
	sm[ind] = mx[ind] = a[l];
	return;
}
int m = l+(r-l)/2;
build(2*ind+1, l, m);
build(2*ind+2, m, r);
sm[ind] = sm[2*ind+1]+sm[2*ind+2];
mx[ind] = max(mx[2*ind+1], mx[2*ind+2]);
}

void calc_d(){
RE(i, 1, A_)
	RE(j, 1, A_){
		if(j>((A_-1)/i)) break;
		d[i*j]++;
	}
//RE(i, 0, min(10, A_)) cerr << d[i] << '\n';
}

void init(){
cin >> n >> m;
RE(i, 1, n+1) cin >> a[i];
calc_d();
build();
}

main(){
init();
RE(i, 0, m){
	cin >> t >> l >> r;
	if(t==1) update(l, r);
	else cout << query(l, r) << '\n';
}
}

//12:13 16-03-2019
//12:29 16-03-2019
//12:32 16-03-2019
