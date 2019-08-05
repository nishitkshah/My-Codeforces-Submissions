//23:39 07-02-2019
//23:48 07-02-2019
//00:42 08-02-2019

#include<iostream>
#include<vector>
//#include<set>
#include<map>
//#include<utility>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100001

int n, c[N_];
vector<int> t[N_];
map<int, int> cnt[N_];
//set< pair<int, long long> > sm[N_];
map<int, long long> sm[N_];
long long ans[N_];

inline void input(){
cin >> n;
RE(i, 1, n+1) cin >> c[i];
int x, y;
RE(i, 1, n){
	cin >> x >> y;
	t[x].push_back(y);
	t[y].push_back(x);
}
}

int dfs(int nd, int pr){
int ind = nd;
cnt[ind][c[nd]] = 1;
sm[ind][1] = (long long)c[nd];
for(auto nc: t[nd])
	if(nc!=pr){
		int cind = dfs(nc, nd);
		if(cnt[ind].size()<cnt[cind].size()) swap(ind, cind);
		for(auto pr: cnt[cind]){
			int x = pr.first, cs=pr.second, cb;
			if(cnt[ind].count(x)){
				cb = cnt[ind][x];
				cnt[ind][x] += cs;
			}else{
				cb = 0;
				cnt[ind][x] = cs;
			}
			sm[ind][cb] -= x;
			if(!sm[ind][cb]) sm[ind].erase(cb);
			if(sm[ind].count(cb+cs)) sm[ind][cb+cs] += x;
			else sm[ind][cb+cs] = (long long) x;
		}
	}
ans[nd] = (sm[ind].rbegin())->second;
return ind;
}

main(){
input();
dfs(1, 0);
RE(i, 1, n+1){
	if(i!=1) cout << ' ';
	cout << ans[i];
}
cout << '\n';
}

//00:41 08-02-2019
//00:42 08-02-2019
//00:46 08-02-2019
