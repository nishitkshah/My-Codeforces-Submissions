//21:31 21-09-2018
//21:35 21-09-2018
//21:50 21-09-2018 - 660C_2.cpp

#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAXN 300000

main(){
	int n, k, a[MAXN], l[MAXN]={0}, cnt=0, ans=0;
	cin >> n >> k;
	RE(i, 0, n) cin >> a[i];
	if(k)
		l[0] = 0;
	else
		l[0] = 1-a[0];
	cnt = 1-a[0];
	if(ans<(1-l[0]))
		ans = 1-l[0];
	RE(i, 1, n){
		l[i] = l[i-1];
		cnt += 1-a[i];
		while(cnt>k){
			cnt -= 1-a[l[i]];
			l[i]++;
		}
		if(ans<(i+1-l[i]))
			ans = i+1-l[i];
	}
	cout << ans << '\n';
}

//21:49 21-09-2018 - Stopped 660C_1.cpp
//22:03 21-09-2018
