//18:30 15-12-2018 to 19:00 15-12-2018 - read editorial
//19:25 15-12-2018
//19:40 15-12-2018
//19:51 15-12-2018

#include<cstdio>
#include<set>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100000

int n, a[N_];
long long s[2*N_];
multiset<long long> st;

main(){
scanf("%d", &n);
RE(i, 0, n){
	scanf("%d", &a[i]);
	s[i] = s[n+i] = a[i];
}
RE(i, 1, 2*n) s[i] += s[i-1];
long long sum=0;
int mx=0;
RE(i, 0, n) st.insert(s[i]);
RE(i, 0, n){
	mx = max(mx, (int)st.count(sum));
	//Prepare for next round
	sum = s[i];
	st.erase(st.find(s[i]));
	st.insert(s[i+n]);
}
printf("%d\n", n-mx);
}

//19:39 15-12-2018
//19:43 15-12-2018
//19:52 15-12-2018
//19:53 15-12-2018
