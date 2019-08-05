//21:47 06-02-2019
//21:58 06-02-2019 to 22:03 06-02-2019 and 22:47 06-02-2019
//23:49 06-02-2019

#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100001
#define V_ 2000000

struct query{
	int l, r, i;
	long long ans;
} q[N_];

int n, m, k, a[N_], cnt[V_]={0}, blk, l, r;
long long ans=0LL;

bool cmp(const query &q1, const query &q2){
if((q1.l/blk)!=(q2.l/blk)) return (q1.l/blk)<(q2.l/blk);
if(q1.r!=q2.r) return q1.r<q2.r;
if(q1.l!=q2.l) return q1.l<q2.l;
return q1.i<q2.i;
}

bool cmpi(const query &q1, const query &q2){
return q1.i<q2.i;
}

main(){
//Input
cin >> n >> m >> k;
a[0] = 0;
RE(i, 1, n+1){
	cin >> a[i];
	a[i] ^= a[i-1];
}
RE(i, 0, m){
	cin >> q[i].l >> q[i].r;
	q[i].i = i;
}
//Init
blk = (int)sqrt((double)n)+1;
sort(q, q+m, cmp);
l = r = 1;
cnt[a[l]] = 1;
if(a[l]==k)
	ans = 1LL;
else
	ans = 0LL;
//Sqrt Decom
RE(i, 0, m){
	while(q[i].r>r){
		r++;		//Used q[i].r instead
		int v = a[r];	//Used q[i].r instead
		ans += cnt[v^k];
		if((v^a[l-1])==k) ans++;
		cnt[v]++;	//missed it initially
	}
	while(q[i].l<l){
		l--;		//Used q[i].l instead
		int v = a[l];	//Used q[i].l instead
		cnt[v]++;
		ans += cnt[a[l-1]^k];
	}
	while(q[i].r<r){
		int v = a[r];
		cnt[v]--;
		if((v^a[l-1])==k) ans--;
		ans -= cnt[v^k];
		r--;
	}
	while(q[i].l>l){
		int v = a[l];
		ans -= cnt[a[l-1]^k];
		cnt[v]--;
		l++;
	}
	q[i].ans = ans;
}
sort(q, q+m, cmpi);
RE(i, 0, m)
	cerr << q[i].ans << '\n';
}

//23:48 06-02-2019
//23:50 06-02-2019
//23:52 06-02-2019
