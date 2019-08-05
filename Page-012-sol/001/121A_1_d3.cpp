//14:20 16-08-2018
//14:27 16-08-2018
//14:48 16-08-2018
//14:50 16-08-2018
//15:14 16-08-2018

#include<iostream>
#include<algorithm>

#ifdef DBG
	#define PI(a) cerr << #a ": " << a << '\n'
#endif
#ifndef DBG
	#define PI(a)
#endif

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

int ln[1<<10];

inline int get_val(int a){
	int ans = 0LL;
	int p = 0;
	RE(i, 1, 11){
		if((1<<i)>a){
			p = i-1;
			break;
		}
	}
	for(int i=(p-1); i>=0; i--){
		ans *= 10;
		if(a&(1<<i)){
			ans += 7;
		}else{
			ans += 4;
		}
	}
	return ans;
}

inline void init(){
	RE(i, 2, 1<<10){
		ln[i] = get_val(i);
	}
}

main(){
	init();
	int l, m, r;
	long long ans = 0LL;
	cin >> l >> r;
	do{
		int ind = lower_bound(ln+2, ln+(1<<10), l)-ln;
		m = min(ln[ind], r);
		ans += (m-l+1)*(long long)ln[ind];
		l = m+1;
	}while(l<=r);
	cout << ans << '\n';
}

//14:47 16-08-2018
//14:49 16-08-2018
//15:13 16-08-2018
//15:23 16-08-2018
//15:24 16-08-2018
