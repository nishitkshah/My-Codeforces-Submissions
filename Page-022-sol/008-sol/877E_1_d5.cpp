//00:35 04-06-2019 to 00:42 04-06-2019
//23:21 09-06-2019
//23:58 09-06-2019
//00:01 10-06-2019
//00:20 10-06-2019
//00:40 10-06-2019
//00:45 10-06-2019

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ (2000 * 101)
//#define N_ 6

int n, q, v, sg[4*N_]={0}, fg[4*N_]={0}, p, ti, start[N_], fin[N_], cnt=0;
vector<int> t[N_];
string s;

void dfs(int nd){
start[nd] = cnt++;
for(auto nc: t[nd])
	dfs(nc);
fin[nd] = cnt-1;
}

void push(int ind, int l, int r){
if(fg[ind]){
	sg[ind] = r-l-sg[ind];
	fg[ind] = 0;
	if(l!=(r-1)){
		fg[2*ind+1] = 1-fg[2*ind+1];
		fg[2*ind+2] = 1-fg[2*ind+2];
	}
}
}

int query(int x, int y, int ind=0, int l=0, int r=N_){
push(ind, l, r);
if(x==l && y==(r-1))
	return sg[ind];
int m = l+(r-l)/2;
if(y<m)
	return query(x, y, 2*ind+1, l, m);
else if(x>=m)
	return query(x, y, 2*ind+2, m, r);
else
	return query(x, m-1, 2*ind+1, l, m) + query(m, y, 2*ind+2, m, r);
}

void update(int x, int y, int ind=0, int l=0, int r=N_){
if(x==l && y==(r-1)){
	fg[ind] = 1-fg[ind];
	push(ind, l, r);
	return;
}
push(ind, l, r);
int m = l+(r-l)/2;
if(y<m)
	update(x, y, 2*ind+1, l, m);
else if(x>=m)
	update(x, y, 2*ind+2, m, r);
else
	update(x, m-1, 2*ind+1, l, m), update(m, y, 2*ind+2, m, r);
push(2*ind+1, l, m);
push(2*ind+2, m, r);
sg[ind] = sg[2*ind+1]+sg[2*ind+2];
}

/*
void print_sgt(int mn, int ind=0, int l=0, int r=N_){
push(ind, l, r);
if((r-1)<=mn) cerr << l << ' ' << r << " : " << sg[ind] << '\n';
if(l==(r-1))
	return;
int m = l+(r-l)/2;
print_sgt(mn, 2*ind+1, l, m);
print_sgt(mn, 2*ind+2, m, r);
}
*/

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n;
RE(i, 2, n+1){
	cin >> p;
	t[p].push_back(i);
}
dfs(1);
RE(i, 1, n+1){
	cin >> ti;
	if(ti) update(start[i], start[i]);
}
//print_sgt(4);
cin >> q;
RE(i, 0, q){
	cin >> s >> v;
	if(s[0]=='g')
		cout << query(start[v], fin[v]) << '\n';
	else
		update(start[v], fin[v]);
}
//cerr << "Dbg: \n";
//RE(i, 1, n+1) cerr << start[i] << ' ' << fin[i] << '\n';
//print_sgt(4);
}

//23:57 09-06-2019
//00:00 10-06-2019
//00:19 10-06-2019
//00:40 10-06-2019
//00:42 10-06-2019
//00:46 10-06-2019
//00:46 10-06-2019
