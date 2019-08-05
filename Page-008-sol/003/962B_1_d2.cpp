//14:26 02-07-2018
//14:49 02-07-2018
//15:01 02-07-2018
//15:04 02-07-2018

#include<cstdio>
#include<algorithm>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int n, a, b, sm, d[100000]={0}, p=0;
char s[200001];

main(){
	scanf("%d%d%d\n%s", &n, &a, &b, s);
	sm = a+b;
	//printf("%d %d %d\n%s\n", n, a, b, s);
	REP(i, 0, n){
		if(s[i]=='.') d[p]++;
		else p++;
	}
	p++;
	REP(i, 0, p){
		if(a<b) swap(a, b);
		int mx = (d[i]+1)/2,
		mn = d[i]/2;
		a = max(a-mx, 0);
		b = max(b-mn, 0);
		//printf("d[i] mx mn a b: %d %d %d\n", d[i], mx, mn, a, b);
	}
	printf("%d\n", sm-(a+b));
}

//15:00 02-07-2018
//15:01 02-07-2018
//15:15 02-07-2018
//15:15 02-07-2018
