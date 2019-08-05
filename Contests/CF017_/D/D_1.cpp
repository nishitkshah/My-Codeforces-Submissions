//21:17 13-04-2019
//21:24 13-04-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 300010

int n, op[N_], f[N_], vi[N_], si[N_];
vector<int> v[N_];

void dfs(int  nd){
	int sz = 1;
	if(op[nd]) vi[nd] = 0;
	else vi[nd] = 2*N_;
	for(auto nc: v[nd]){
		sz = 0;
		dfs(nc);
		si[nd] += si[nc];
	}
	si[nd] += sz;
	for(auto nc: v[nd]){
		if(op[nd]) vi[nd] = max(vi[nd], vi[nc]+si[nd]-si[nc]);
		else vi[nd] = min(vi[nd], vi[nc]+si[nd]-si[nc]);
	}
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n;
RE(i, 1, n+1) cin >> op[i];
RE(i, 2, n+1){
	cin >> f[i];
	v[f[i]].push_back(i);
}
dfs(1);
cout << vi[1] << '\n';
}

//21:34 13-04-2019 - tried to submit at 21:35 13-04-2019 but failed - solution is wrong
