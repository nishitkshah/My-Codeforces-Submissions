//21:45 02-07-2018
//21:50 02-07-2018
//22:06 02-07-2018

#include<cstdio>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAX 200002

int n, k, q, l, r;
long long t[MAX]={0};

main(){
	scanf("%d%d%d", &n, &k, &q);
	RE(i, 0, n){
		scanf("%d%d", &l, &r);
		t[l] += 1;
		t[r+1] -= 1;
	}
	RE(i, 1, MAX) t[i] += t[i-1];
	RE(i, 0, MAX) t[i] = (t[i]>=k ? 1 : 0);
	RE(i, 1, MAX) t[i] += t[i-1];
	RE(i, 0, q){
		scanf("%d%d", &l, &r);
		printf("%d\n", t[r]-t[l-1]);
	}
}

//22:01 02-07-2018
//22:08 02-07-2018
//22:08 02-07-2018
