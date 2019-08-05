//18:11 11-12-2018
//18:20 11-12-2018

#include<cstdio>
#include<set>
#include<utility>
#include<algorithm>
#include<vector>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define SI(a) scanf("%d", &(a))
#define N_ 2000

typedef pair< int, pair<int, int> > piii;

int n, d[N_][N_], r[N_], dist[N_][N_]={0}, vis[N_]={0};
set<piii> st;
vector<int> mst[N_];

void init(){
	RE(i, 0, n) r[i] = -1;
}

int par(int x){
	int ans = x;
	while(r[ans]>=0)
		ans = r[ans];
	int c=x, p=r[x];
	while(p>=0){
		r[c] = ans;
		c = p;
		p = r[c];
	}
	return ans;
}

bool merge(int x, int y){
int px=par(x), py=par(y);
if(px==py) return false;
if(r[px]>r[py]) swap(px, py);
r[px] += r[py];
r[py] = px;
return true;
}

void dfs(int v, int p, int p_dist=0){
if(!vis[v]){
	vis[v] = 1;
	dist[p][v] = p_dist;
	for(auto nv: mst[v]){
		dfs(nv, p, p_dist+d[v][nv]);
	}
}
}

main(){
SI(n);
RE(i, 0, n)
	RE(j, 0, n){
		SI(d[i][j]);
		if( (i==j && d[i][j]) || (j>i && d[i][j]!=d[j][i])){
			printf("NO\n");
			return 0;
		}
		if(j<i)
			st.insert({d[i][j], {i, j}});
	}
init();

//MST
set<piii>::iterator p;
while(st.size()){
	p = st.begin();
	st.erase(p);
	if(merge((*p).second.first, (*p).second.second)){
		mst[(*p).second.first].insert((*p).second.second);
		mst[(*p).second.second].insert((*p).second.first);
	}
}

//APSP
RE(src, 0, n){
	RE(i, 0, n) vis[i] = 0;
	dfs(src, src);
}

//Verification
RE(i, 0, n)
	RE(j, 0, n)
		if(d[i][j] != dist[i][j]){
			printf("NO\n");
			return 0;
		}
printf("YES\n");
}

//19:03 11-12-2018
