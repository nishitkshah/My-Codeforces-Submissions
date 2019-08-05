#include<cstdio>
#include<vector>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)
#define SI(a) scanf("%d", &(a))

typedef vector<int> vi;
typedef vector<vi> graph;

int n, m, a, b;
int vis[100010]={0}, cvc[100010]={0}, cec[100010]={0};
graph g(100010);

void dfs(int v, int c){
	if(vis[v]!=-1) return;
	vis[v] = c;
	REP(i, 0, g[v].size())
		dfs(g[v][i], c);
}

int main(){
	SI(n);
	SI(m);
	REP(i, 0, m){
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	REP(i, 0, n) vis[i] = -1;
	int cmp=0;
	REP(i, 0, n){
		if(vis[i]!=0){
			dfs(i, cmp++);
		}
	}
	REP(i, 0, n){
		cec[vis[i]] += g[i].size();
		cvc[vis[i]]++;
	}
	REP(i, 0, cmp){
		cec[i] /= 2;
	}
	int cnt = 0;
	REP(i, 0, cmp){
		if(cvc[i]==1) cnt++;
		if((cvc[i]-1)==cec[i]) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
