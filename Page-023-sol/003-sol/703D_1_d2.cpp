//01:19 04-07-2019 to 01:26 04-07-2019
//22:30 04-07-2019 to 22:47 04-07-2019 and 22:56 04-07-2019
//23:15 04-07-2019
//23:36 04-07-2019

#include<bits/stdc++.h>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 1000010
#define FF first
#define SS second

int n, a[N_], m, ans[N_], pre[N_];
pair< pair<int, int>, int> q[N_];	//{{r, l}, i}
int bit[N_] = {0};
unordered_map<int, int> lst;

void insert(int x, int v){
while(x<=n){
	bit[x] ^= v;
	x += x&(-x);
}
}

int query(int x){
int ans = 0;
while(x){
	ans ^= bit[x];
	x -= x&(-x);
}
return ans;
}

int query(int l, int r){
if(l==1) return query(r);
return query(r)^query(l-1);
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n;
RE(i, 1, n+1) cin >> a[i];
cin >> m;
RE(i, 0, m){
	cin >> q[i].FF.SS >> q[i].FF.FF;
	q[i].SS = i;
}
sort(q, q+m);
pre[0] = 0;
RE(i, 1, n+1) pre[i] = pre[i-1]^a[i];
//cerr << "DBG: ";
//RE(i, 0, n+1) cerr << pre[i] << ' ';
//cerr << '\n';
int qi = 0;
RE(i, 1, n+1){
	if(lst.count(a[i]))
		insert(lst[a[i]], a[i]);
	lst[a[i]] = i;
	insert(i, a[i]);
	//cerr << "ARR: \n";
	//RE(j, 1, i+1) cerr << bit[j] << ' '; cerr << '\n';
	//RE(j, 1, i+1) cerr << j << ' '; cerr << '\n';
	while(q[qi].FF.FF==i){
		int l=q[qi].FF.SS, r=q[qi].FF.FF;
		//cerr << "DBG: " << l << ' ' << r << ": ";
		//cerr << (pre[r]^pre[l-1]) << ' ' << query(l, r) << '\n';
		ans[q[qi].SS] = pre[r]^pre[l-1]^query(l, r);
		qi++;
	}
}
RE(i, 0, m) cout << ans[i] << '\n';
}

//23:14 04-07-2019
//23:15 04-07-2019
//23:58 04-07-2019
//23:59 04-07-2019
