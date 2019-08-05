//19:08 03-02-2019 to 19:54 03-02-2019
//21:04 05-02-2019
//22:21 05-02-2019

#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 200000
#define LIM 4e9L
#define EPS 1e-8L

int n;
long long a[N_];
long double mx, cmx;

long double chk(long double x, int mul){
mx = cmx = mul*((long double)a[0]-x);
RE(i, 1, n){
	long double cv = mul*((long double)a[i]-x);
	cmx = max(cv, cmx+cv);
	mx = max(mx, cmx);
}
return mx;
}

long double b_search(){
long double l=-LIM, m, h=LIM;
m = (l+h)/2;
RE(i, 0, 80){
	if(fabs(chk(m, 1)-chk(m, -1))<EPS)
		break;
	//cerr << chk(m, 1) << ' ' << chk(m, -1) << '\n';
	if(chk(m, 1)>chk(m, -1)) l = m;
	else h = m;
	m = (l+h)/2;
}
return chk(m, 1);
}

main(){
cin >> n;
RE(i, 0, n) cin >> a[i];
cout << fixed << setprecision(9) << b_search() << '\n';
}

//21:48 05-02-2019
//22:27 05-02-2019
//22:29 05-02-2019 - testcases created after submitting - 22:33 05-02-2019
