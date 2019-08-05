//15:35 02-07-2018
//15:37 02-07-2018

#include<cstdio>
#include<cstring>

using namespace std;

#define MAX 1000001

char a[MAX], b[MAX];
int n1, n2;

main(){
	scanf("%*[0]s%s\n%*[0]%*[0]s%s", a, b);
	n1 = strlen(a);
	n2 = strlen(b);
	if(n1!=n2){
		if(n1>n2) printf(">\n");
		else printf("<\n");
		return 0;
	}
	for(int i=0; i<n1; i++){
		if(a[i]!=b[i]){
			if(a[i]>b[i]) printf(">\n");
			else printf("<\n");
			return 0;
		}
	}
	printf("=\n");
}

//15:48 02-07-2018
