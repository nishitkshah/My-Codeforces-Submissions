//14:26 02-07-2018
//14:49 02-07-2018

#include<cstdio>
#include<algorithm>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int n, a, b, d[100000]={0}, p=0;
char s[200001];

main(){
	scanf("%d%d%d\n%s", &n, &a, &b, s);
	REP(i, 0, n){
		if(s[i]=='.') d[p]++;
		else p++;
	}
	p++;
	REP(i, 0, p){
		if(a<b) swap(a, b);
		int mx = (d[p]+1)/2,
		mn = d[p]/2;
		a = max(a-mx, 0);
		b = max(b-mn, 0);
	}
	cout << a+b << '\n';
}

//15:00 02-07-2018
