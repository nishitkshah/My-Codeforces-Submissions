#include<cstdio>

int main(){
	int x = 0, n;
	char c[3];
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%s", c)
		if(c[0]=='+'||c[2]=='+') x++;
		else x--;
	}
	printf("%d\n", &x);
	return 0;
}
