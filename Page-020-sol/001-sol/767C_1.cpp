//22:51 09-02-2019
//23:00 09-02-2019

#include<iostream>
#include<vector>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 1000001

int n, p[N_], t[N_], c[N_];
vector<int> v[N_];

int dfs(int nd){
c[nd] = t[nd];
for(auto nc: v[nd])
	if(p[nc]==nd)
		c[nd] += dfs(nc);
return c[nd];
}
main(){
cin >> n;
int rt=0;
RE(i, 1, n+1){
	cin >> p[i] >> t[i];
	if(!p[i])
		rt = i;
	v[p[i]].push_back(i);
}
dfs(rt);
int sm = c[rt];
if(sm%3){
	cout << "-1\n";
	return 0;
}
sm /= 3;
int nd1=0, nd2=0;
RE(i, 1, n+1)
	if(i!=rt && c[i]==sm)
		nd1 = i;
if(nd1){
	p[nd1] = 0;
}else{
	cout << "-1\n";
	return 0;
}
dfs(rt);
RE(i, 1, n+1)
	if(i!=rt && c[i]==sm)
		nd2 = i;
if(!nd2){
	cout << "-1\n";
	return 0;
}
cout << nd1 << ' ' << nd2 << '\n';
}

//23:20 09-02-2019
