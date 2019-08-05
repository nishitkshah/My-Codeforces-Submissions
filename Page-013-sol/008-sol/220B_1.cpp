//17:02 13-10-2018
//17:09 13-10-2018

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
		if((this.l/BLK)!=(b.l/BLK))
			return this.l/BLK<b.l/BLK;
		return this.r<b.r;
	}
};

bool cmp(query a, query b){
	return a.i<b.i;
}

main(){
	int n, m, a[MAXN], c[MAXN+1]={1}, s[MAXN];
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
	}
	sort(q, q+m);
	int cnt=0, l=0, r=0;
	RE(i, 0, m){
		while(q[i].l<l){
			l--;
			c[a[l]]++;
			if(c[a[l]]==a[l]) cnt++;
		}
		while(q[i].l>l){
			if(c[a[l]]==a[l]) cnt--;
			c[a[l]]--;
			l++;
		}
		while(q[i].r<r){
			if(c[a[r]]==a[r]) cnt--;
			c[a[r]]--;
			r--;
		}
		while(q[i].r>r){
			r++;
			c[a[r]]++;
			if(c[a[r]]==a[r]) cnt++;
		}
		q[i].a = cnt;
	}
}

//17:45 13-10-2018
