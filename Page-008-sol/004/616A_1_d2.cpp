//15:35 02-07-2018
//15:37 02-07-2018
//15:49 02-07-2018

#include<cstdio>
#include<cstring>

using namespace std;

#define MAX 1000001

char a[MAX], b[MAX], *p, *q;
int n1, n2;

main(){
	p = a; q = b;
	scanf("%s\n%s", p, q);
	while(p[0]=='0') p++;
	while(q[0]=='0') q++;
	n1 = strlen(p);
	n2 = strlen(q);
	if(n1!=n2){
		if(n1>n2) printf(">\n");
		else printf("<\n");
		return 0;
	}
	for(int i=0; i<n1; i++){
		if(p[i]!=q[i]){
			if(p[i]>q[i]) printf(">\n");
			else printf("<\n");
			return 0;
		}
	}
	printf("=\n");
}

//15:48 02-07-2018
//15:52 02-07-2018
//15:55 02-07-2018
//15:56 02-07-2018
