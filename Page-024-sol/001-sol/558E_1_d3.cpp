//21:39 23-07-2019 to 22:00 23-07-2019
//23:27 24-07-2019
//00:07 25-07-2019
//08:44 25-07-2019
//19:12 25-07-2019 to 19:48 25-07-2019 and 22:35 25-07-2019

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
	int m = l+(r-l)/2;
	lz[i][2*ind+1] = lz[i][2*ind+2] = 1;
	st[i][2*ind+1] = m-l;
	st[i][2*ind+2] = r-m;
}else{
	st[i][ind] = 0;
	lz[i][ind] = 0;
	if(l==(r-1)) return;
	lz[i][2*ind+1] = lz[i][2*ind+2] = -1;
	st[i][2*ind+1] = st[i][2*ind+2] = 0;
}
}

void update(int i, int x, int y, int v, int ind=0, int l=0, int r=N_){
if(ind>(4*N_))
	cerr << "U x y " << x << ' ' << y << endl;
push_down(i, ind, l, r);
if(x==l && y==(r-1)){
	lz[i][ind] = v;
	if(v==1) st[i][ind] = r-l;
	else if(v==-1) st[i][ind] = 0;
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
push_down(i, 2*ind+1, l, m);
push_down(i, 2*ind+1, m, r);
st[i][ind] = st[i][2*ind+1] + st[i][2*ind+2];
}

int query(int i, int x, int y, int ind=0, int l=0, int r=N_){
if(ind>(4*N_))
	cerr << "Q x y " << x << ' ' << y << endl;
//cerr << "Q" << ind << endl;
push_down(i, ind, l, r);
if(x==l && y==(r-1)) return st[i][ind];
int m = l + (r-l)/2;
if(y<m) return query(i, x, y, 2*ind+1, l, m);
if(x>=m) return query(i, x, y, 2*ind+2, m, r);
return query(i, x, m-1, 2*ind+1, l, m)
	+ query(i, m, y, 2*ind+2, m, r);
}

void tree_traverse(int i, int N, int ind=0, int l=0, int r=N_){
if(r<=N)
	cerr << ind << ": " << l << " " << r << " " << st[i][ind] << " " << lz[i][ind] << '\n';
if(l==(r-1)) return;
int m = l + (r-l)/2;
tree_traverse(i, N, 2*ind+1, l, m);
tree_traverse(i, N, 2*ind+2, m, r);
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
	cerr << "CNT: ";
	RE(i, 0, 26){
		cnt[i] = query(i, x, y);
		cerr << cnt[i] << ' ';
		//cerr << "CNT: " << cnt[i] << endl;
		if(_q==3 && i==0) tree_traverse(i, n+1);	//Mismatch in count of letter a for 4th query
		update(i, x, y, -1);
	}
	cerr << '\n';
	if(k){
		RE(i, 0, 26){
			if(cnt[i]) update(i, x, x+cnt[i]-1, 1);
			x += cnt[i];
		}
	}else{
		for(int i=25; i>=0; i--){
			//cerr << "i L R: " << i << ' ' << x << ' ' << x+cnt[i]-1 << '\n';
			if(cnt[i]) update(i, x, x+cnt[i]-1, 1);
			x += cnt[i];
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
	cerr << "DBG: " << s << '\n';
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
RE(i, 0, 4){
	cerr << "I: " << i << ":\n";
	//tree_traverse(i, n+1);
}
}

//00:06 25-07-2019
//00:28 25-07-2019
//08:46 25-07-2019
//23:12 25-07-2019
