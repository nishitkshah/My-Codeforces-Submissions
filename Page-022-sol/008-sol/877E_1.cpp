//00:35 04-06-2019 to 00:42 04-06-2019
//23:21 09-06-2019

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ (2000 * 100)

int n, q, v, sg[4*N_]={0}, fg[4*N_]={0}, p, ti, start[N_], end[N_], cnt=0;
vector<int> t[N_];
string s;

void dfs(int nd){
start[nd] = cnt++;
for(auto nc: t[nd])
	dfs(nc);
end[nd] = cnt-1;
}

void push(int ind, bool leaf=false){
if(fg[ind]){
	sg[ind] = end[ind]-start[ind]+1-sg[ind];
	fg[ind] = 0;
	if(!leaf){
		fg[2*ind+1] = 1-fg[2*ind+1];
		fg[2*ind+2] = 1-fg[2*ind+2];
	}
}
}

int query(int x, int y, int ind=0, int l=0, int r=N_){
push(ind, l==(r-1));
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
	push(ind, l==(r-1));
	return;
}
push(ind, l==(r-1));
int m = l+(r-l)/2;
if(y<m)
	return update(x, y, 2*ind+1, l, m);
else if(x>=m)
	return update(x, y, 2*ind+2, m, r);
else
	return update(x, m-1, 2*ind+1, l, m) + update(m, y, 2*ind+2, m, r);
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n;
RE(i, 2, n+1){
	cin >> p;
	t[p].push_back(i);
}
RE(i, 1, n+1){
	cin >> ti;
	if(ti) update(start[i], start[i]);
}
cin >> q;
RE(i, 0, q){
	cin >> s >> v;
	if(s[0]=='g')
		cout << query(start[v], end[v]) << '\n';
	else
		update(start[v], end[v]);
}
}

//23:57 09-06-2019
