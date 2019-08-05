//09:55 31-10-2018 to 10:01 31-10-2018
//21:42 31-10-2018

#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 200000

int n, k, a, m, x[N_], p[N_];

bool chk(int mv){
RE(i, 0, n) p[i] = 1;
RE(i, 0, mv+1) p[x[i]] = 0;
RE(i, 1, n)
	if(p[i])
		p[i] = (p[i-1]+1)%(a+1);
int cnt = 0;
RE(i, 0, n)
	if(p[i]==a) cnt++;
return cnt>=k;
}

int b_search(int n){
int l=0, h=n;
if(!b_search(l)) return l;
while(l!=(h-1)){
	int m = l + (h-l)/2;
	if(b_search(m)) l = m;
	else h = m;
}
return h;
}

main(){
cin >> n >> k >> a >> m;
RE(i, 0, m) cin >> x[i];
int ans = b_search(n);
if(ans==n) ans = -1;
else ans++;
cout << ans << '\n';
}

//21:55 31-10-2018
