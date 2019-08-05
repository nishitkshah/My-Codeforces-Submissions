//20:31 04-01-2019
//20:42 04-01-2019

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 1000000

int n, l;
int p[N_]={0}, m[N_]={0};
char c[N_];

int val(){
int cnt = 0, mn=0;
bool neg = false;
RE(i, 0, l){
	if(c[i]=='(') cnt++;
	else cnt--;
	mn = min(cnt, mn);
	if(cnt<0) neg = true;
}
if(cnt>0 && mn<0) return N_;
if(cnt<0 && mn<cnt) return N_;
return cnt;
}

main(){
scanf("%d", &n);
RE(i, 0, n){
	scanf("%s", c);
	l = strlen(c);
	int v = val();
	if(v<N_){
		if(v<0) m[-v]++;
		else p[v]++;
	}
}
int ans = 0;
RE(i, 1, N_) ans += min(p[i], m[i]);
ans += p[0]/2;
printf("%d\n", ans);
}

//20:58 04-01-2019
//20:59 04-01-2019
