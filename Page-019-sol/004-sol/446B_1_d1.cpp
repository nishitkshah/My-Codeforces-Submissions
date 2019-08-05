//10:40 02-02-2019 - read editorial
//11:14 02-02-2019
//11:41 02-02-2019

#include<iostream>
#include<set>
#include<algorithm>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 1000
#define K_ 1000001
#define NEGINF -1000000000000000000LL

int n, m, k, p, a[N_][N_];
set< pair<int, int> > r, c;	//Max abs val is 1e8
long long ans=NEGINF, rm[K_], cm[K_];

main(){
cin >> n >> m >> k >> p;
RE(i, 0, n)
	RE(j, 0, m) cin >> a[i][j];
RE(i, 0, n){
	int rc=0;
	RE(j, 0, m) rc += a[i][j];
	r.insert({rc, i});
}
RE(j, 0, m){
	int cc=0;
	RE(i, 0, n) cc += a[i][j];
	c.insert({cc, j});
}
rm[0] = cm[0] = 0LL;
RE(i, 1, k+1){
	pair<int, int> pr = *r.rbegin();
	r.erase(pr);
	rm[i] = rm[i-1]+pr.first;
	pr.first -= m*p;
	r.insert(pr);
}
RE(i, 1, k+1){
	pair<int, int> pr = *c.rbegin();
	c.erase(pr);
	cm[i] = cm[i-1]+pr.first;
	pr.first -= n*p;
	c.insert(pr);
}
RE(kr, 0, k+1){
	long long kc = k-kr;
	ans = max(ans, rm[kr]+cm[kc]-kc*kr*p);
}
cout << ans << '\n';
}

//11:35 02-02-2019
//11:44 02-02-2019
//11:46 02-02-2019
