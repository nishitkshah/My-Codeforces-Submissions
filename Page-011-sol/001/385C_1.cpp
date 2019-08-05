//19:11 08-08-2018 to 19:30 08-08-2018
//15:05 09-08-2018 to 15:19 09-08-2018 and 15:41 09-08-2018

#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAXN 1000000
#define MAXP 10000001

int n, x[MAXN], m, l, r, p[MAXP]={0}, cnt[MAXP]={0};

void sieve(){
	RE(i, 2, MAXP){
		if(!p[i]){
			for(int j=2; (i*j)<MAXP; j++){
				p[i*j] = i;
			}
		}
	}
}

void update_cnt(){
	RE(i, 0, n){
		int v = x[i];
		while(p[v]){
			cnt[p[v]]++;
			while( (v%p[v]) == 0 ) v /= p[v];
		}
		cnt[v]++;	// v is prime or 1
	}
	cnt[1] = 0;
	RE(i, 3, MAXP)
		cnt[i] += cnt[i-1];
}

main(){
	sieve();
	cin >> n;
	RE(i, 0, n) cin >> x[i];
	update_cnt();
	cin >> m;
	RE(i, 0, m){
		cin >> l >> r;
		cout << cnt[r]-cnt[l-1] << '\n';
	}
}

//15:46 09-08-2018