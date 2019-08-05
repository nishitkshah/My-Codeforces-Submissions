//22:47 05-12-2018 to 22:59 05-12-2018
//16:04 06-12-2018
//16:42 06-12-2018
//16:43 06-12-2018
//16:59 06-12-2018

#include<cstdio>
#include<algorithm>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define SI(a) scanf("%d", &(a))
#define N_ 1000000
#ifdef _DBG
	#define PE(x) printf(x)
	#define PEII(x, y) printf(#x " " #y " : %d %d\n", x, y)
#else
	#define PE(x)
	#define PEII(x, y)
#endif

int n, a[N_], l[4*N_]={0}, g[4*N_]={0};
pair<int, int> p[N_];

int query(int s[], int x, int y, int ind=0, int l=0, int r=n){
PEII(x, y);
PEII(ind, ind);
PEII(l, r);
if(x>=r) return 0;
if(x==l && y==r) return s[ind];
int m = l + (r-l)/2;
if(y<=m) return query(s, x, y, 2*ind+1, l, m);
if(x>=m) return query(s, x, y, 2*ind+2, m, r);
return query(s, x, m, 2*ind+1, l, m) + query(s, m, y, 2*ind+2, m, r);
}

void update(int s[], int x, int v, int ind=0, int l=0, int r=n){
PEII(x, ind);
PEII(l, r);
//if(x>=r) return;	//not needed in this problem
if(l==(r-1)){
	s[ind] = v;
	return;
}
int m = l+(r-l)/2;
if(x<m) update(s, x, v, 2*ind+1, l, m);
else update(s, x, v, 2*ind+2, m, r);
}

void build_g(int s[], int ind=0, int l=0, int r=n){
s[ind] = r-l;
if(l==(r-1)) return;
int m = l+(r-l)/2;
build_g(s, 2*ind+1, l, m);
build_g(s, 2*ind+2, m, r);
}

main(){
SI(n);
RE(i, 0, n){
	SI(a[i]);
	p[i] = {a[i], i};
}
sort(p, p+n);
build_g(g);
PE("Build done\n");
long long ans=0LL;
RE(i, 0, n){
	int v=p[i].first, pos=p[i].second;
	update(g, pos, 0);
	long long mul = 1LL*query(g, 0, pos)*query(l, pos+1, n);
	ans += mul;
	update(l, pos, 1);
}
printf("%I64d\n", ans);
}

//16:41 06-12-2018
//16:42 06-12-2018
//16:59 06-12-2018
//17:05 06-12-2018
