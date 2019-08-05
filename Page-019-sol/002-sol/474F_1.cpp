//23:53 28-01-2019 to 00:02 29-01-2019
//20:40 29-01-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100000

int n, s[4*N_]={0}, p=0, m, l, r;
unordered_map<int, int> mp;
vector<int> v[N_];

inline void add2mp(int l, int i){
if(!mp.count(l)) mp[l] = p++;
v[mp[l]].push_back(i);
}

int gcd(int x, int y){
if(!x || !y) return x+y;
return gcd(y, x%y);
}

void init(){
RE(i, 0, 4*N_) s[i] = 1;
}

void insert(int v, int p, int ind=0, int l=0, int r=N_){
if(l==(r-1)){
	s[ind] = v;
	return;
}
int m = l+(r-l)/2+1;	//+1 to keep [l,m) [m, r)
if(p<m) insert(v, p, 2*ind+1, l, m);
else insert(v, p, 2*ind+2, m, r);
s[ind] = gcd(s[2*ind+1], s[2*ind+2]);
}

int query(int x, int y, int ind=0, int l=0, int r=N_){ //y inclusive
if(x<=l && r<=(y+1)) return s[ind];
int m = l+(r-l)/2+1;	//+1 to keep [l,m) [m, r)
if(y<=(m-1)) return query(x, y, 2*ind+1, l, m);
if(x>=m) return query(x, y, 2*ind+2, m, r);
return gcd(query(x, m-1, 2*ind+1, l, m), query(m, y, 2*ind+2, m, r));
}

main(){
init();
cin >> n;
RE(i, 0, n){
	int v;
	cin >> v;
	insert(v, i);
	add2mp(v, i);
}
cin >> m;
RE(i, 0, m){
	cin >> l >> r;
	l--, r--;
	int g = query(l, r);
	int ans = 0;
	if(mp.count(g)){
		int ind = mp[g];
		ans = upper_bound(v[ind].begin(), v[ind].end(), r)-lower_bound(v[ind].begin(), v[ind].end(), l);
	}
	cout << ans << '\n';
}
}

//21:16 29-01-2019
