#include<cstdio>
#include<cstring>

int main(){
	char a[101];
	int n, cnt=0;
	scanf("%s", a);
	n = strlen(a);
	if(n<7){
		printf("NO\n");
		return 0;
	}
	for(int i=0; i<7; i++) cnt+=a[i]-'0';
	for(int i=7; i<n; i++){
		if(cnt==0||cnt==7){
			printf("YES\n");
			return 0;
		}
		cnt-=(a[i-7]-'0');
		cnt+=a[i]-'0';
	}
	if(cnt==0||cnt==7) printf("YES\n");
	else printf("NO\n");
	return 0;
}
