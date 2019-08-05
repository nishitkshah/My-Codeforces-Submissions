//11:29 14-08-2018
//11:34 14-08-2018
//12:04 14-08-2018
//12:23 14-08-2018

#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAX 100000

int n, a[MAX], s[MAX], vis[MAX]={0};
unordered_map<int, int> ind, mp;
vector< vector<int> > v;

void dfs(int i){
	if(vis[i]) return;
	int nxt = i;
	while(true){
		v[i].push_back(nxt+1);
		vis[nxt] = 1;
		if(mp[nxt]==i) break;
		nxt = mp[nxt];
	}
}

main(){
	cin >> n;
	v.resize(n);
	RE(i, 0, n){
		cin >> a[i];
		s[i] = a[i];
		ind[a[i]] = i;
	}
	sort(s, s+n);
	RE(i, 0, n){
		mp[i] = ind[s[i]];
	}
	RE(i, 0, n){
		dfs(i);
	}
	int cnt = 0;
	RE(i, 0, n) if(v[i].size()) cnt++;
	cout << cnt << '\n';
	RE(i, 0, n){
		if(v[i].size()){
			cout << v[i].size();
			RE(j, 0, v[i].size())
				cout << ' ' << v[i][j];
			cout << '\n';
		}
	} 
}

//11:40 14-08-2018
//12:22 14-08-2018
//12:33 14-08-2018
//12:35 14-08-2018
