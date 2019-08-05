#include<cstdio>

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int main(){
	int n, a, b, c=0, mc=0;
	scanf("%d", &n);
	REP(i, 0, n){
		scanf("%d%d", &a, &b);
		c = c-a+b;
		if(mc<c) mc = c;
	}
	printf("%d\n", mc);
	return 0;
}
