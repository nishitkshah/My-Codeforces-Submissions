#include<cstdio>

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int main(){
	int n, t, p=0, cnt=0;
	scanf("%d", &n);
	n=3*n;
	REP(i, 0, n){
		if(i%3==0){
			if(p>1) cnt++; 
			p = 0;
		}
		scanf("%d", &t);
		p+=t;
	}
	if(i%3==0){
		if(p>1) cnt++; 
		p = 0;
	}
	printf("%d", cnt);
	return 0;
}
