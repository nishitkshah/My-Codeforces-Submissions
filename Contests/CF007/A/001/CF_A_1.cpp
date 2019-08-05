#include<cstdio>

using namespace std;

char a[101], b[101];

int main(){
	scanf("%s%s", a, b);
	int i=0;
	while(a[i]==b[i]){
		if(a[i]==0){
			printf("%s\n", a);
			return 0;
		}
		i++;
	}
	printf("1\n");
	return 0;
}
