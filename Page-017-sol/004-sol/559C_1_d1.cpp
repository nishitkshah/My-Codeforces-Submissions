//21:51 16-12-2018 to 21:57 16-12-2018 and 23:24 16-12-2018 to 23:30 16-12-2018
//14:51 24-12-2018 to 15:51 24-12-2018 and 16:12 24-12-2018
//16:25 24-12-2018

#include<iostream>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define W_ 100001
#define N_ 2001
#define MD 1000000007

struct cell{
int r, c;
};

bool cmp(struct cell a, struct cell b){
	if(a.r!=b.r) return a.r<b.r;
	return a.c<b.c;
}

int h, w, n;
cell c[N_];
long long dp[N_], fc[W_], ifc[W_];

long long pow(long long a, int p=MD-2){
long long rem = 1LL;
while(p){
	if(p&1){
		rem *= a;
		rem %= MD;
	}
	a *= a;
	a %= MD;
	p >>= 1;
}
return rem;
}

void init(){
fc[0] = ifc[0] = 1LL;
fc[1] = ifc[1] = 1LL;
RE(i, 2, W_)
	fc[i] = (i*fc[i-1])%MD;
RE(i, 2, W_)
	ifc[i] = (pow(i)*ifc[i-1])%MD;
}

long long nCr(int n, int r){
if(n<0 || r<0) return 0LL;
return ( ((fc[n]*ifc[r])%MD) *ifc[n-r]) % MD;
}

main(){
init();
cin >> h >> w >> n;
RE(i, 0, n)
	cin >> c[i].r >> c[i].c;
c[n].r = h, c[n].c = w;
n++;
sort(c, c+n, cmp);
RE(i, 0, n){
	dp[i] = nCr(c[i].r+c[i].c-2, c[i].c-1);
	RE(j, 0, i){
		dp[i] -= (dp[j]*nCr((c[i].r-c[j].r)+(c[i].c-c[j].c), c[i].r-c[j].r))%MD;
		dp[i] = (dp[i]+MD) % MD;
	}
}
cout << dp[n-1] << '\n';
}

//16:20 24-12-2018
//16:28 24-12-2018
//16:34 24-12-2018
