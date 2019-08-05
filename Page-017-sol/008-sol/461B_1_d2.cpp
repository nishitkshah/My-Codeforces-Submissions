//00:15 27-12-2018 to 00:17 27-12-2018 and 23:14 01-01-2019 to 23:46 01-01-2019 - read editorial
//23:46 01-01-2019
//00:05 02-01-2019
//00:25 02-01-2019

#include<iostream>
#include<vector>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MD 1000000007
#define N_ 100000

int n, c[N_];
vector<int> v[N_];
long long B[N_], W[N_];

void dfs(int r){
B[r] = 0LL;
W[r] = 1LL;
for(auto ch: v[r]){
	dfs(ch);
	B[r] *= W[ch];	//Root r is white but and part of embedded-tree rooted at children encountered before c having a single black node
	B[r] %= MD;
	B[r] += W[r]*B[ch];	//Root r is white and part of embedded-tree rooted at c having a single black node
	B[r] %= MD;
	W[r] *= W[ch];
	W[r] %= MD;
}
if(c[r])
	B[r] = W[r];
else
	W[r] += B[r];
B[r] %= MD;
W[r] %= MD;
//cerr << r << ' ' << W[r] << ' ' << B[r] << '\n';
}

main(){
cin >> n;
int t;
RE(i, 1, n){
	cin >> t;
	v[t].push_back(i);
}
RE(i, 0, n) cin >> c[i];
dfs(0);
cout << B[0] << '\n';
/*
RE(i, 0, n){
	cerr << i << " : ";
	for(auto ch: v[i])
		cerr << ch << ' ';
	cerr << '\n';
}
*/
}

//00:04 02-01-2019
//00:05 02-01-2019
//00:33 02-01-2019 - error in testcase and not in code
//00:36 02-01-2019
