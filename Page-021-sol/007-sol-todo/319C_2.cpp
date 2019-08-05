//19:55 13-03-2019
//20:04 13-03-2019
//20:14 13-03-2019
//21:21 15-03-2019 - 319C_2.cpp

#include<iostream>
#include<algorithm>
//#include<deque>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100001
#define INF 1.0e12L

struct line{
	long long m, c;
	long double xl, xr;
	line(long long m, long long c, long long xl, long long xr):
		m(m), c(c), xl(xl), xr(xr)
		{}
};

int n, qi=0;
long long ans=INF, a[N_], b[N_], dp[N_];
//deque<line> q;
line q[N_];	//Since the lines will always be sorted by their slope (i.e.: b[i]), new lines will always be added to the right.

long double eval(long long long m, long double x, long long c){
return m*x+c;
}

long long b_search(long double x){
int l=0, h=qi-1;
if(q[h].xl<=x)
	return h;
while(l!=(h-1)){
	int m = l+(h-l)/2;
	if(q[m].xl<=x) l = m;
	else h = m;
}
return l;
}

main(){
cin >> n;
RE(i, 0, n) cin >> a[i];
RE(i, 0, n) cin >> b[i];
dp[0] = 0;
line l(-b[0], -dp[0], -INF, INF);
q[qi++] = l;
RE(i, 1, n){
	long double x = (long double)a[i];
	int j = b_search(x);
	dp[i] = -(q[j].m*a[i]+q[j].c);
	line bk = q[qi-1];
	while(qi && eval(bk.m, bk.xl, bk.c)<eval(b[i], bk.xl, dp[i])){
		qi--;
		if(qi) bk = q[qi-1];
	}
	line l(-b[i], -dp[i], -INF, INF);
	q[qi++] = l;
	if(qi>1){
		long double xm = ((long double)q[qi-2].c-q[qi-1].c)/(q[qi-1].m-q[qi-2].m);
		q[qi-2].xr = xml
		q[qi-1].xl = xm;
	}
}

cout << dp[n-1] << '\n';
}

//20:11 13-03-2019
//20:14 13-03-2019
//22:17 15-03-2019
