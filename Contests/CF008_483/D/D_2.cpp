//20:55 15-05-2018
//20:58 15-05-2018
//21:35 15-05-2018 - D_2.cpp

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

struct query{
	int l, blk, r, ind, ans;
};

const int MAXN = 5010;
const int BLOCK = 75;

int a[MAXN];
vector<query> v;

bool cmp(struct query a, struct query b){
	if(a.blk!=b.blk) return a.blk<b.blk;
	if(a.l!=b.l) return a.l<b.l;
	return a.ind<b.ind;
}

bool cmp2(struct query a, struct query b){
	return a.ind<b.ind;
}

int main(){
	int n, q, l, r, ans = 0;
	cin >> n;
	REP(i, 1, n+1){
		cin >> a[i];
	}
	cin >> q;
	v.resize(q);
	REP(i, 0, q){
		cin >> l >> r;
		v[i].l = l;
		v[i].r = r;
		v[i].blk = r/BLOCK;
		v[i].ind = i;
	}
	sort(v.begin(), v.end(), cmp);
	l = 0;
	r = 0;
	ans = 0;
	REP(i, 0, q){
		int lc = v[i].l, rc = v[i].r;
		while(r>rc){
			ans ^= a[r];
			r--;
			//Mo's Algo incomplete
		}
	}
	sort(v.begin(), v.end(), cmp2);
	return 0;
}

//21:24 15-05-2018
