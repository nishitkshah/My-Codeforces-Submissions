//20:21 13-01-2019 - used template
//20:25 13-01-2019

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100001

int n, m, pc[N_], pt[N_], t[N_], l=N_;
vector<int> p[N_];

main(){
cin >> n >> m;
RE(i, 0, m){
	cin >> pc[i];
	pc[i]--;
	p[pc[i]].push_back(i);
}
RE(i, 0, n) l = min(l, p[i].size());
RE(i, 0, l){
	pt[i] = 0;
	RE(ind, 0, n){
		pt[i] = max(pt[i], p[ind][i]);
	}
}
RE(i, 0, m) t[i] = 0;
RE(i, 0, l) t[pt[i]] = 1;
RE(i, 0, m) cout << t[i];
cout << '\n';
}

//20:34 13-01-2019
