//18:11 11-12-2018
//18:20 11-12-2018
//00:03 12-12-2018
//00:05 12-12-2018
//00:12 12-12-2018
//00:23 12-12-2018
//22:00 14-12-2018

#include<cstdio>
//#include<set>
#include<utility>
#include<algorithm>
#include<vector>
//#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define SI(a) scanf("%d", &(a))
#define N_ 2000

typedef pair< int, pair<int, int> > piii;

int n, d[N_][N_], r[N_], dist[N_][N_]={0}, vis[N_]={0};
vector<piii> st;
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
//cerr << "M: " << x << " " << y << "\n";
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
		if( (i==j && d[i][j]) || (i!=j && !d[i][j]) || (i>j && d[i][j]!=d[j][i])){
			printf("NO\n");
			return 0;
		}
		if(j<i)
			st.push_back({d[i][j], {i, j}});
	}
sort(st.begin(), st.end());
init();

/*
for(auto s: st){
	cerr << s.first << " " << s.second.first << " " << s.second.second << "\n";
}
*/

//MST
vector<piii>::iterator p;
while(st.size()){
	p = st.begin();
	//cerr << (*p).first << " " << (*p).second.first << " " << (*p).second.second << "\n";
	if(merge((*p).second.first, (*p).second.second)){
		mst[(*p).second.first].push_back((*p).second.second);
		mst[(*p).second.second].push_back((*p).second.first);
	}
	st.erase(p);
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
//00:04 12-12-2018
//00:08 12-12-2018
//00:23 12-12-2018
//00:25 12-12-2018
//22:02 14-12-2018
//22:05 14-12-2018
