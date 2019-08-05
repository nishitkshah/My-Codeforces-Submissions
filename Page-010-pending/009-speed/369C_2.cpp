//15:22 08-08-2018

#include<iostream>
#include<vector>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAXN 100010

int n;
vector< vector<int> > v, prob;
vector<int> cand;

int dfs(int nd=1, int par=0, int r2p=0){
	int sum = 0, sz = v[nd].size();
	for(int i=0; i<sz; i++){
		int nxt = v[nd][i];
		if(nxt!=par){
			sum += dfs(nxt, nd, prob[nd][i]);
		}
	}
	if(r2p==1 && sum==0){
		cand.push_back(nd);
		return 1;
	}
	return sum;
}

main(){
	int n;
	cin >> n;
	v.resize(n+1);
	prob.resize(n+1);
	RE(i, 0, n-1){
		int a, b, c;
		cin >> a >> b >> c;
		c--;
		v[a].push_back(b);
		v[b].push_back(a);
		prob[a].push_back(c);
		prob[b].push_back(c);
	}
	dfs();
	cout << cand.size() << '\n';
	RE(i, 0, cand.size()){
		if(i) cout << ' ';
		cout << cand[i];
	}
	cout << '\n';
}

//15:48 08-08-2018
//15:49 08-08-2018
