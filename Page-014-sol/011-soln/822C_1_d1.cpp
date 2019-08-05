//23:39 21-10-2018
//23:49 21-10-2018
//00:16 22-10-2018

#include<iostream>
#include<set>
#include<cstdio>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define SI(a) scanf("%d", &(a))
#define N_ 200000
#define TENp9 1000000000

struct ticket{
	int l, r, c, d;
};

struct compare_left{
	bool operator()(const ticket& a, const ticket& b){
		return a.l < b.l;
	}
} cmpl;

struct compare_right{
	bool operator()(const ticket& a, const ticket& b){
		return a.r < b.r;
	}
} cmpr;

struct compare_days{
	bool operator()(const ticket& a, const ticket& b){
		if(a.d!=b.d) return a.d<b.d;
		if(a.c!=b.c) return a.c<b.c;
		if(a.l!=b.l) return a.l<b.l;
		if(a.r!=b.r) return a.r<b.r;
	}
};

int n, x;
ticket ls[N_], rs[N_];

main(){
cin >> n >> x;
RE(i, 0, n){
	cin >> ls[i].l >> ls[i].r >> ls[i].c;
	ls[i].d = ls[i].r - ls[i].l + 1;
	rs[i] = ls[i];
}
sort(ls, ls+n, cmpl);
sort(rs, rs+n, cmpr);
set<ticket, compare_days> st(rs, rs+n);
int ans = 2*TENp9;
int l=0;
RE(i, 0, n){
	ticket ct = rs[i];
	int cost = ans;
	while(l<n && ls[l].l<=ct.r){
		st.erase(ls[l]);
		l++;
	}
	int rem = x - ct.d;
	ticket srch;
	srch.d = rem; srch.c = 0;
	srch.l = 0; srch.r = 0;
	set<ticket>::iterator lb = st.lower_bound(srch);
	if(lb!=st.end()) cost = (*lb).c + ct.c;
	ans = min(cost, ans);
}
cout << ans << '\n';
}

//00:15 22-10-2018
//00:16 22-10-2018
