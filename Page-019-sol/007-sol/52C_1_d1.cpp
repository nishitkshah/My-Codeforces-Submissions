//23:40 05-02-2019
//23:47 05-02-2019
//00:24 06-02-2019

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<iterator>
#include<string>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 200000
#define S_ 4*N_

int n, m, lf, rg;
long long st[S_]={0LL}, lz[S_]={0LL}, v;

void propagate(int ind){
st[ind] += lz[ind];
if((2*ind+2)<S_){
	lz[2*ind+1] += lz[ind];
	lz[2*ind+2] += lz[ind];
}
lz[ind] = 0;
}

long long query(int x, int y, int ind=0, int l=0, int r=N_-1){
//cerr << "q dbggg: " << x << ' ' << y << '\n';
propagate(ind);
if(x==l && y==r) return st[ind];
int m = l+(r-l)/2;
if(y<=m) return query(x, y, 2*ind+1, l, m);
if(x>m) return query(x, y, 2*ind+2, m+1, r);
return min(
	query(x, m, 2*ind+1, l, m),
	query(m+1, y, 2*ind+2, m+1, r)
);
}


void update(long long v, int x, int y, int ind=0, int l=0, int r=N_-1){
propagate(ind);
if(x==l && y==r){
	lz[ind] += v;
	return;
}
int m = l+(r-l)/2;
if(y<=m) update(v, x, y, 2*ind+1, l, m);
else if(x>m) update(v, x, y, 2*ind+2, m+1, r);
else{
	update(v, x, m, 2*ind+1, l, m);
	update(v, m+1, y, 2*ind+2, m+1, r);
}
st[ind] = min(st[2*ind+1]+lz[2*ind+1], st[2*ind+2]+lz[2*ind+2]);
}

main(){
cin >> n;
RE(i, 0, n){
	long long t;
	cin >> t;
	update(t, i, i);
}
cin >> m;
string s;
getline(cin, s);
RE(i, 0, m){
	getline(cin, s);
	//cerr << "Dbggg: " << s << '\n';
	istringstream is(s);
	vector<int> vc( (istream_iterator<int>(is)), istream_iterator<int>());
	lf = vc[0]; rg = vc[1];
	if(vc.size()==2){
		long long ans = 0LL;
		if(lf<=rg) ans = query(lf, rg);
		else ans = min(query(lf, n-1), query(0, rg));
		cout << ans << '\n';
	}else{
		v = vc[2];
		if(lf<=rg) update(v, lf, rg);
		else{
			update(v, lf, n-1);
			update(v, 0, rg);
		}
	}
}
}

//00:21 06-02-2019
//00:31 06-02-2019
//00:33 06-02-2019
