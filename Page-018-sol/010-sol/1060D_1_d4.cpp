//19:55 27-01-2019 to 20:06 27-01-2019 - read announcement comments & solution "https://codeforces.com/contest/1060/submission/43768975" - Trying the hard way though
//21:59 27-01-2019
//22:18 27-01-2019
//22:24 27-01-2019
//22:59 27-01-2019
//23:10 27-01-2019 - compared submissions https://codeforces.com/contest/1060/submission/44064431 and https://codeforces.com/contest/1060/submission/44064461

#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100000

struct g{
	int l, r, i;
};

struct cmp_l{
bool operator()(const g &a, const g &b){
	if(a.l!=b.l) return a.l<b.l;
	if(a.r!=b.r) return a.r<b.r;
	return a.i<b.i;
}
};

struct cmp_r{
bool operator()(const g &a, const g &b){
	if(a.r!=b.r) return a.r<b.r;
	if(a.l!=b.l) return a.l<b.l;
	return a.i<b.i;
}
};

int n;
g a[N_];
set<g, cmp_l> sl;
set<g, cmp_r> sr;

main(){
cin >> n;
RE(i, 0, n){
	a[i].i = i;
	cin >> a[i].l >> a[i].r;
	sl.insert(a[i]);
	sr.insert(a[i]);
}
long long chr = 0LL;
RE(i, 0, n){
	g ml, mr, mi;
	ml = *(sl.rbegin());
	mr = *(sr.rbegin());
	//cerr << "Dbggg: i l r " << ml.i << ' ' << ml.l << ' ' << ml.r << ' ' << mr.i << ' ' << mr.l << ' ' << mr.r << '\n';
	chr += max(ml.l, mr.r)+1LL;
	//cerr << "chr: " << chr << '\n';
	sl.erase(ml);
	sr.erase(mr);
	if(ml.i!=mr.i){
		//cerr << "In no match\n";
		sl.erase(mr);
		sr.erase(ml);
		mi.i = ml.i;
		mi.l = mr.l;
		mi.r = ml.r;
		sl.insert(mi);
		sr.insert(mi);
	}
	//for(auto gi: sl){
	//	cerr << "Dbggg: l " << gi.i << ' ' << gi.l << ' ' << gi.r << '\n';
	//}
	//for(auto gi: sr){
	//	cerr << "Dbggg: r " << gi.i << ' ' << gi.l << ' ' << gi.r << '\n';
	//}
}
cout << chr << '\n';
}

//22:16 27-01-2019
//22:22 27-01-2019
//22:31 27-01-2019
//23:05 27-01-2019
//23:11 27-01-2019
//23:12 27-01-2019