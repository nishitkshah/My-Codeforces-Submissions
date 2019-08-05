//21:39 23-07-2019 to 22:00 23-07-2019
//23:27 24-07-2019
//00:07 25-07-2019

#include<bits/stdc++.h>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ (1001*100)

int n, q, st[26][4*N_]={0}, lz[26][4*N_]={0}, cnt[26], x, y, k;
string s;

inline void push_down(int i, int ind, int l, int r){
if(!lz[i][ind]) return;
if(lz[i][ind]==1){
	st[i][ind] = r-l;
	lz[i][ind] = 0;
	if(l==(r-1)) return;
	lz[i][2*ind+1] = lz[i][2*ind+2] = 1;
}else{
	st[i][ind] = 0;
	lz[i][ind] = 0;
	if(l==(r-1)) return;
	lz[i][2*ind+1] = lz[i][2*ind+2] = -1;
}
}

void update(int i, int x, int y, int v, int ind=0, int l=0, int r=N_){
if(ind>(4*N_))
	cerr << "U x y " << x << ' ' << y << endl;
push_down(i, ind, l, r);
if(x==l && y==(r-1)){
	lz[i][ind] = v;
	push_down(i, ind, l, r);	// Very Important
	return;
}
int m = l + (r-l)/2;
if(y<m) update(i, x, y, v, 2*ind+1, l, m);
else if(x>=m) update(i, x, y, v, 2*ind+2, m, r);
else{
	update(i, x, m-1, v, 2*ind+1, l, m);
	update(i, m, y, v, 2*ind+2, m, r);
}
st[i][ind] = st[i][2*ind+1] + st[i][2*ind+2];
}

int query(int i, int x, int y, int ind=0, int l=0, int r=N_){
if(ind>(4*N_))
	cerr << "Q x y " << x << ' ' << y << endl;
cerr << "Q" << ind << endl;
push_down(i, ind, l, r);
if(x==l && y==(r-1)) return st[i][ind];
int m = l + (r-l)/2;
if(y<m) return query(i, x, y, 2*ind+1, l, m);
if(x>=m) return query(i, x, y, 2*ind+2, m, r);
return query(i, x, m-1, 2*ind+1, l, m)
	+ query(i, m, y, 2*ind+2, m, r);
}

main(){
/*
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
cin >> n >> q >> s;
RE(i, 0, n)
	update(s[i]-'a', i, i, 1);
RE(_q, 0, q){
	cin >> x >> y >> k;
	x--, y--;
	RE(i, 0, 26){
		cnt[i] = query(i, x, y);
		cerr << "CNT: " << cnt[i] << endl;
		update(i, x, y, -1);
	}
	if(k){
		RE(i, 0, 26){
			if(cnt[i]) update(i, x, x+cnt[i]-1, 1);
			x += cnt[i];
		}
	}else{
		for(int i=25; i>=0; i--){
			if(cnt[i]) update(i, x, x+cnt[i]-1, 1);
			x += cnt[i];
		}
	}
}
RE(i, 0, n){
	RE(j, 0, 26){
		if(query(j, i, i)){
			s[i] = 'a'+j;
			break;
		}
	}
}
cout << s << '\n';
}

//00:06 25-07-2019
//00:28 25-07-2019
