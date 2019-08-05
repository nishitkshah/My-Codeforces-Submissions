#include<cstdio>
#include<algorithm>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

char s[101], c;
int n, ind, pc, nc, r1, r2;

int main(){
	c = 0;
	ind = pc = nc = 0;
	while(c!='='){
		scanf("%c", &c);
		if(c=='+') pc++, (s[ind++] = c);
		if(c=='-') nc++, (s[ind++] = c);
	}
	scanf("%d", &n);
	r1 = n*(pc+1) - nc;
	r2 = pc+1 - (n*nc);
	if(r1<n||r2>n){
		printf("Impossible\n");
		return 0;
	}
	printf("Possible\n");
	int pv=max(pc+1, nc+n), nv, res=0;
	nv = pv;
	pv -= pc+1;
	nv -= nc+n;
	res = min(pv, n-1)+1;
	printf("%d", res);
	pv -= res-1;
	REP(i, 0, pc+nc){
		if(s[i]=='+'){
			res = min(pv, n-1)+1;
			printf(" + %d", res);
			pv = pv+1-res;
		}else{
			res = min(nv, n-1)+1;
			printf(" - %d", res);
			nv = nv+1-res;
		}
	}
	printf(" = %d\n", n);
	return 0;
}
