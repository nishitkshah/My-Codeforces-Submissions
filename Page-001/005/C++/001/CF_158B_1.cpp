#include<cstdio>

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int main(){
	int n, s, ct=0, cnt=0;
	scanf("%d", &n);
	REP(i, 0, n){
		scanf("%d", &s);
		ct = ct+s;
		if(ct>4){
			ct = s;
			cnt++;
		}
	}
	cnt++;
	printf("%d\n", cnt);
	return 0;
}
