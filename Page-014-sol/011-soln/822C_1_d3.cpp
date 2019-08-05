//23:39 21-10-2018
//23:49 21-10-2018
//00:16 22-10-2018
//00:17 22-10-2018
//00:23 22-10-2018

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
		return a.r<b.r;
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
int ans = 2*TENp9+1;
int l=0;
RE(i, 0, n){
	ticket ct = rs[i];
	cerr << "DBG CT: " << ct.d << " " << ct.c << " " << ct.l << " " << ct.r << "\n";
	int cost = ans;
	while(l<n && ls[l].l<=ct.r){
		cerr << "DBG REM: " << ls[l].d << " " << ls[l].c << " " << ls[l].l << " " << ls[l].r << "\n";
		int cnt = st.erase(ls[l]);
		set<ticket>::iterator fnd = st.find(ls[l]);
		if(fnd==st.end()) cerr << "Elem not found\n";
		else cerr << "DBG fnd: " << (*fnd).d << " " << (*fnd).c << " " << (*fnd).l << " " << (*fnd).r << "\n";
		cerr << "DBG CNT: " << cnt << "\n";
		l++;
	}
	for(auto t: st){
		cerr << "DBG LST: " << t.d << " " << t.c << " " << t.l << " " << t.r << "\n";
	}
	int rem = x - ct.d;
	ticket srch;
	srch.d = rem; srch.c = 0;
	srch.l = 0; srch.r = 0;
	set<ticket>::iterator lb = st.lower_bound(srch);
	if(lb!=st.end() && (*lb).d==rem){
		cerr << "DBG LB: " << (*lb).d << " " << (*lb).c << " " << (*lb).l << " " << (*lb).r << "\n";
		cost = (*lb).c + ct.c;
	}
	ans = min(cost, ans);
}
if(ans == (2*TENp9+1)) ans = -1;
cout << ans << '\n';
}

//00:15 22-10-2018
//00:16 22-10-2018
//00:19 22-10-2018
//00:37 22-10-2018
