//08:17 23-04-2019 to 08:39 23-04-2019
//23:49 23-04-2019

#include<iostream>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ (100 * 1001)

int n, m, st[4*N_]={0}, t, l, r, x;	//st stores max
long long sm[4*N_]={0LL};

long long query(int x, int y, int ind=0, int l=0, int r=N_){
if(x<=l && (r-1)<=y) return sm[ind];
int m = l+(r-l)/2;
if(y<m) return query(x, y, 2*ind+1, l, m);
else if(x>=m) return query(x, y, 2*ind+2, m, r);
else return query(x, m, 2*ind+1, l, m)
	+ query(m, y, 2*ind+2, m, r);
}

void update2(int x, int y, int v, int ind=0, int l=0, int r=N_){
if(st[ind]<v) return;
int m = l+(r-l)/2;
if(y<m) update2(x, y, v, 2*ind+1, l, m);
else if(x>=m) update2(x, y, v, 2*ind+2, m, r);
else{
	update2(x, m, v, 2*ind+1, l, m);
	update2(m, y, v, 2*ind+2, m, r);
}
st[ind] = max(st[2*ind+1], st[2*ind+2]);
sm[ind] = sm[2*ind+1]+sm[2*ind+2];
}

void update3(int x, int v, int ind=0, int l=0, int r=N_){
if(l==(r-1)){
	sm[ind] = st[ind] = v;
	return;
}
int m = l+(r-l)/2;
if(x<m) update3(x, v, 2*ind+1, l, m);
else update3(x, v, 2*ind+2, m, r);
st[ind] = max(st[2*ind+1], st[2*ind+2]);
sm[ind] = sm[2*ind+1]+sm[2*ind+2];
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> m;
RE(i, 1, n+1){
	cin >> t;
	update3(i, t);
}
RE(i, 0, m){
	cin >> t;
	switch(t){
		case 1:
			cin >> l >> r;
			cout << query(l, r) << '\n';
			break;
		case 2:
			cin >> l >> r >> x;
			update2(l, r, x);
			break;
		case 3:
			cin >> l >> x;
			update3(l, x);
			break;
	}
}
}

//00:15 24-04-2019
