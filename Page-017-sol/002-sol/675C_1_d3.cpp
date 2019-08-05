//18:30 15-12-2018 to 19:00 15-12-2018 - read editorial
//19:25 15-12-2018
//19:40 15-12-2018
//19:51 15-12-2018
//19:54 15-12-2018

#include<cstdio>
#include<map>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100000

int n, a[N_];
long long s[2*N_];
map<long long, int> mp;

main(){
scanf("%d", &n);
RE(i, 0, n){
	scanf("%d", &a[i]);
	s[i] = s[n+i] = a[i];
}
RE(i, 1, 2*n) s[i] += s[i-1];
long long sum=0;
int mx=0;
RE(i, 0, n)
	if(mp.count(s[i]))
		mp[s[i]]++;
	else
		mp[s[i]] = 1;
RE(i, 0, n){
	mx = max(mx, mp[sum]);
	//Prepare for next round
	sum = s[i];
	mp[s[i]]--;
	if(mp.count(s[i+n]))
		mp[s[i+n]]++;
	else
		mp[s[i+n]] = 1;
}
printf("%d\n", n-mx);
}

//19:39 15-12-2018
//19:43 15-12-2018
//19:52 15-12-2018
//19:57 15-12-2018
//19:58 15-12-2018
