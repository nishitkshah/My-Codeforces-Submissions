//14:20 16-08-2018
//14:27 16-08-2018

#include<iostream>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

long long ln[1<<11];

inline long long get_val(int a){
	long long ans = 0LL;
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
	RE(i, 2, 1<<11){
		ln[i] = get_val(i);
	}
}

main(){
	init();
	int l, m, r;
	long long ans = 0LL;
	cin >> l >> r;
	do{
		int ind = upper_bound(ln+2, ln+(1<<11), l)-(ln+2);
		m = min(ln[ind]-1, r);
		ans += (m-l+1)*ln[ind];
		l = m+1;
	}while(l<=r);
	cout << ans << '\n';
}

//14:47 16-08-2018
