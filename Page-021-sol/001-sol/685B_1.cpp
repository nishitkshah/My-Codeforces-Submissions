//20:20 07-03-2019 to 20:30 07-03-2019
//21:04 07-03-2019

#include<iostream>
#include<algorithm>
#include<set>
//#include<utility>
#include<vector>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 300001

int n, q, p[N_], sz[N_], mp[N_], c[N_];
vector<int> t[N_];

struct cmp{
	bool operator()(const int &a, const int &b){
		if(sz[a]!=sz[b]) return sz[a]<sz[b];
		return a<b;
	}
};

set<int, cmp> st[N_];

void input(){
cin >> n >> q;
RE(i, 2, n+1){
	cin >> p[i];
	t[p[i]].push_back(i);
}
}

int dfs(int nd){
sz[nd] = 1;
for(auto nc: t[nd])
	sz[nd] += dfs(nc);
int mx=nd, mn;
st[mx].insert(nd);
for(auto nc: t[nd]){
	mn = nc;
	if(st[mx].size()<st[mn].size())
		swap(mx, mn);
	for(auto sv: st[mn])
		st[mx].insert(sv);
}
int hsz = (sz[nd]+1)/2;
while(sz[*st.begin()]<hsz){
	st.erase(st.begin());
}
c[nd] = *st.begin();
mp[nd] = mx;
return sz[nd];
}

/*
void init(){
RE(i, 0, n+1) mp[i] = i;
dfs(1);
}
*/

main(){
input();
//init();
dfs(1);
int v;
RE(i, 0, q){
	cin >> v;
	cout << c[v] << '\n';
}
}

//21:34 07-03-2019
