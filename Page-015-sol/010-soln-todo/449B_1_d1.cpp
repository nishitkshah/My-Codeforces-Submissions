//08:21 02-11-2018
//08:31 02-11-2018
//09:06 02-11-2018

#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100000
#define TENp9 1000000000LL
#define INF (N_*(TENp9+1))

int n, m, k;
vector<int> r[N_];
vector<long long> rw[N_];
long long dist[N_], rdist[N_], tw[N_];

inline void init(){
RE(i, 0, n) tw[i] = INF, dist[i] = INF;
dist[0] = 0LL;
}

inline void input(){
cin >> n >> m >> k;
int u, v, s;
long long x, y;
RE(i, 0, m){
	cin >> u >> v >> x;
	u--, v--;
	r[u].push_back(v);
	rw[u].push_back(x);
	r[v].push_back(u);
	rw[v].push_back(x);
}
init();
RE(i, 0, k){
	cin >> s >> y;
	s--;
	tw[s] = min(tw[s], y);
}
}

main(){
input();
set< pair<long long, int> > st;
st.insert({dist[0], 0});
while(st.size()){
	pair<long long, int> p = *(st.begin());
	long long w=p.first;
	int nd=p.second;
	rdist[nd] = w;
	dist[nd] = min(dist[nd], tw[nd]);
	w = dist[nd];
	for(int i=0; i<r[nd].size(); i++){
		int nx = r[nd][i];
		st.erase({dist[nx], nx});
		dist[nx] = min(dist[nx], dist[nd]+rw[nd][i]);
		st.insert({dist[nx], nx});
	}
	st.erase(p);
}
int ans=0;
RE(i, 0, n)
	if(tw[i]<INF && tw[i]>=rdist[i])
		ans++;
cout << ans << '\n';
}

//09:04 02-11-2018
//09:08 02-11-2018
