//20:59 07-08-2018
//21:09 07-08-2018 to 21:32 07-08-2018 and 22:57 07-08-2018 to 23:06 07-08-2018 and 14:42 08-08-2018
//15:08 08-08-2018
//15:49 08-08-2018

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAXN 100010

int n;
vector< vector<int> > v, p;
int vis[MAXN]={0}, par[MAXN], ret[MAXN]={0}, road[MAXN]={0};
vector<int> cand;

void dfs(){
	stack<int> s;
	s.push(0);
	par[0] = 0;
	road[0] = 0;
	while(s.size()){
		int c = s.top();
		if(vis[c]!=v[c].size()){
			int nxt = v[c][vis[c]];
			if(!vis[nxt]){
				par[nxt] = c;
				road[nxt] = p[c][vis[c]];
				s.push(nxt);
				vis[c]++;
				continue;
			}
		}else{
			int sum = 0;
			RE(i, 0, v[c].size()){
				int nxt = v[c][i];
				if(nxt!=par[c]){
					sum += ret[nxt];
				}
			}
			ret[c] = max(sum, road[c]);
			if(sum==0 && road[c]){
				cand.push_back(c);
			}
			s.pop();
		}
	}
}

main(){
	cin >> n;
	v.resize(n); p.resize(n);
	RE(i, 0, n-1){
		int a, b, r;
		cin >> a >> b >> r;
		a--, b--, r--;
		v[a].push_back(b);
		p[a].push_back(r);
		v[b].push_back(a);
		p[b].push_back(r);
	}
	dfs();
	cout << cand.size() << '\n';
	RE(i, 0, cand.size()){
		if(i) cout << ' ';
		cout << cand[i]+1;
	}
	cout << '\n';
}

//15:05 08-08-2018
//15:09 08-08-2018
//15:50 08-08-2018
//15:51 08-08-2018
