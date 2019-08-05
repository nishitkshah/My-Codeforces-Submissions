#include<cstdio>

using namespace std;

int main(){
	int n, m, a;
	scanf("%d%d%d", &n, &m, &a);
	printf("%I64d\n", (((long long) n+a-1)/a)*(((long long) m+a-1)/a));
	return 0;
}
