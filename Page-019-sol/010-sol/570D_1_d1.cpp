//23:29 08-02-2019
//23:46 08-02-2019
//00:23 09-02-2019

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 500001

int n, m, p[N_], mp[N_], rl[N_], cnt=0, up[N_];
vector<int> t[N_], h[N_], c[N_];
string s;

inline void dfs(int nd, int dpt){
cnt++;
mp[nd] = cnt;
rl[cnt] = nd;
h[dpt].push_back(cnt);
int msk = 1<<(s[nd-1]-'a');
c[dpt].push_back(msk);
for(auto nc: t[nd])
	dfs(nc, dpt+1);
up[nd] = cnt;
}

inline void input(){
cin >> n >> m;
RE(i, 2, n+1){
	cin >> p[i];
	t[p[i]].push_back(i);
}
cin >> s;
RE(i, 0, N_){
	h[i].push_back(0);
	c[i].push_back(0);
}
}

inline void preprocess(){
RE(d, 1, N_)
	RE(i, 1, c[d].size())
		c[d][i] ^= c[d][i-1];
}

int bit_cnt(int v){
int ans = 0;
RE(i, 0, 30)
	if(v&(1<<i))
		ans++;
return ans;
}

bool solve(int v, int ht){
int l, u, mn = mp[v], mx = up[v];
l = lower_bound(h[ht].begin(), h[ht].end(), mn) - h[ht].begin();
u = upper_bound(h[ht].begin(), h[ht].end(), mx) - h[ht].begin();
l--, u--;
int ans = c[ht][u]^c[ht][l];
return bit_cnt(ans)<=1;
}

main(){
input();
dfs(1, 1);
int v, ht;
preprocess();
RE(i, 0, m){
	cin >> v >> ht;
	cout << (solve(v, ht) ? "Yes" : "No") << '\n';
}
}

//00:22 09-02-2019
//00:23 09-02-2019
//00:29 09-02-2019
