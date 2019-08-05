//22:51 09-02-2019
//23:00 09-02-2019
//23:22 09-02-2019 - this will work even when sum is 0 and we mark the highest non-root 0-sum node as nd1. This is because nd2 will be marked as it's child having 0-sum (if one exists).
//23:41 09-02-2019

#include<iostream>
#include<vector>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 1000001

int n, p[N_], t[N_], c[N_], rt=0, sm=0, nd1=0, nd2=0;
vector<int> v[N_];

int dfs(int nd, int &ct){
c[nd] = t[nd];
for(auto nc: v[nd])
	if(p[nc]==nd)
		c[nd] += dfs(nc, ct);
if(c[nd]==sm && !ct)
	ct = nd;
return c[nd];
}

main(){
cin >> n;
RE(i, 1, n+1){
	cin >> p[i] >> t[i];
	if(!p[i])
		rt = i;
	v[p[i]].push_back(i);
	sm += t[i];
}
if(sm%3){
	cout << "-1\n";
	return 0;
}
sm /= 3;
dfs(rt, nd1);
if(nd1){
	p[nd1] = 0;
}else{
	cout << "-1\n";
	return 0;
}
dfs(rt, nd2);
if(!nd2){
	cout << "-1\n";
	return 0;
}
cout << nd1 << ' ' << nd2 << '\n';
}

//23:20 09-02-2019
//23:22 09-02-2019
//23:51 09-02-2019
//23:53 09-02-2019
