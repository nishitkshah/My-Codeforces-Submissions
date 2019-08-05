#include<cstdio>
#include<cstring>

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int main(){
	char s[101], t[101], c;
	int n, d;
	scanf("%s%s", s, t);
	n = strlen(s);
	if('a'<'A') c = 'A', d = 'A'-'a';
	else c = 'a', d = 'a'-'A';
	REP(i, 0, n){
		if(s[i]<c) s[i]+=d;
		if(t[i]<c) t[i]+=d;
		if(s[i]<t[i]){
			printf("-1\n");
			return 0;
		}
		if(s[i]>t[i]){
			printf("1\n");
			return 0;
		}
	}
	printf("0\n");
	return 0;
}
