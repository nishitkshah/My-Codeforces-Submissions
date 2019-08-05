//18:20 01-11-2018 - read editorial
//18:48 01-11-2018

#include<iostream>
#include<set>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 200000

struct seg{
int l, r, ind;
};

bool cmpl(const seg& a, const seg& b){
if(a.l!=b.l) return a.l<b.l;
if(a.r!=b.r) return a.r<b.r;
return a.ind<b.ind;
}

bool cmpr(const seg& a, const seg& b){
if(a.r!=b.r) return a.r<b.r;
if(a.l!=b.l) return a.l<b.l;
return a.ind<b.ind;
}

int n;
seg s[N_];

main(){
cin >> n;
RE(i, 0, n){
	int x, w;
	cin >> x >> w;
	seg[i].l = x-w;
	seg[i].r = x+w;
	seg[i].ind = i;
}
set<seg> sl(s, s+n, cmpl);
set<seg> sr(s, s+n, cmpr);
int cnt = 0;
while(sr.size()){
	seg bg = *(sr.begin());
	cnt++;
	int lt = bg.r;
	while(sl.size() && (sl.begin()->l) < lt){
		sr.erase(*(sl.begin()));
		sl.erase(sl.begin());
	}
}
cout << cnt << '\n';
}

//19:02 01-11-2018
