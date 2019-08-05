//17:02 13-10-2018
//17:09 13-10-2018
//17:46 13-10-2018
//17:49 13-10-2018
//18:00 13-10-2018

#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAXN 100000

int BLK;

struct query{
	int l, r, i, a;
	bool operator < (const query b){
		if(((*this).l/BLK)!=(b.l/BLK))
			return (*this).l/BLK<b.l/BLK;
		return (*this).r<b.r;
	}
};

bool cmp(query a, query b){
	return a.i<b.i;
}

main(){
	int n, m, a[MAXN], c[MAXN+1]={MAXN+1}, s[MAXN];
	query q[MAXN];
	cin >> n >> m;
	BLK = (int)sqrt(m);
	RE(i, 0, n){
		cin >> a[i];
		if(a[i]>MAXN) a[i] = 0;
	}
	RE(i, 0, m){
		q[i].i = i; q[i].a = 0;
		cin >> q[i].l >> q[i].r;
		q[i].l--; q[i].r--;
	}
	sort(q, q+m);
	int cnt=0, l=0, r=0;
	c[a[0]]++;
	if(c[a[0]]==a[0]) cnt++;
	RE(i, 0, m){
		int e;
		while(q[i].l<l){
			l--;
			e = a[l];
			if(e && c[e]==e) cnt--;
			c[e]++;
			if(e && c[e]==e) cnt++;
		}
		while(q[i].l>l){
			e = a[l];
			if(e && c[e]==e) cnt--;
			c[e]--;
			if(e && c[e]==e) cnt++;
			l++;
		}
		while(q[i].r<r){
			e = a[r];
			if(e && c[e]==e) cnt--;
			c[e]--;
			if(e && c[e]==e) cnt++;
			r--;
		}
		while(q[i].r>r){
			r++;
			e = a[r];
			if(e && c[e]==e) cnt--;
			c[e]++;
			if(e && c[e]==e) cnt++;
		}
		q[i].a = cnt;
	}
	sort(q, q+m, cmp);
	RE(i, 0, m) cout << q[i].a << '\n';
}

//17:45 13-10-2018
//17:48 13-10-2018
//17:52 13-10-2018
//18:10 13-10-2018
//18:11 13-10-2018
