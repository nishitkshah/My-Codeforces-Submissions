#include<cstdio>

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int main(){
	int n, cnt=0;
	int c[5] = {0, 0, 0, 0, 0};
	scanf("%d", &n);
	REP(i, 0, n){
		scanf("%d", &s);
		c[s]++;
	}
	cnt = c[4]+c[3];
	if(c[3]<c[1]) c[1] -= c[3];
	else c[1] = 0;
	c[1] = (c[1]+1)/2;
	cnt += (c[2]+c[1]+1)/2;
	printf("%d\n", cnt);
	return 0;
}
