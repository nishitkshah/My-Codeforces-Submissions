//22:40 20-04-2019 to 23:01 20-04-2019
//21:06 22-04-2019

#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ (100*1001)
#define INF (1000 * 1000 * 1000 + 10)
#define FF first
#define SS second

int n, p[N_];
long long h[N_];
pair< pair<int, int>, int > r[N_];

main(){
cin >> n;
RE(i, 0, n){
	cin >> r[i].FF.SS >> r[i].FF.FF >> r[i].SS;
	r[i].FF.SS = -r[i].FF.SS;
	r[i].FF.FF = -r[i].FF.FF;
}
r[n].FF.SS = 0, r[n].FF.FF = -INF, r[n].SS = 0;
n++;
sort(r, r+n);
RE(i, 0, n){
	h[i] = r[i].SS;
	p[i] = 0;
	r[i].FF.FF = -r[i].FF.FF;
	r[i].FF.SS = -r[i].FF.SS;
}
RE(i, 1, n){
	int pr = i-1;
	while(r[i].FF.FF<=r[pr].FF.SS)
		pr = p[pr];
	p[i] = pr;
	h[i] = r[i].SS+h[pr];
}
long long mx = 0LL;
RE(i, 0, n) mx = max(mx, h[i]);
cout << mx << '\n';
}

//21:22 22-04-2019
//21:25 22-04-2019
