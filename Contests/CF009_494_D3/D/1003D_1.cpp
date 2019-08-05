//20:56 03-07-2018
//21:06 03-07-2018

#include<iostream>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define IA(a, i, x, y) for(int i=(x); i<(y); i++) cin >> a[i];

int n, q, do[31]={0}, a, b, d[31];

int bcnt(int a){
	int b=0;
	while(a){
		b++;
		a = a>>1;
	}
	return b;
}

int chk(int b, int p){
	int ans = 0;
	for(int i=p; b&&(i>=0); i--){
		int sub = max(d[i]-(b/(1<<i)), 0);
		b -= sub*(1<<i);
		d[i] -= sub;
		ans += sub;
	}
	return ans;
}

int cnt(int a){
	int b = 1, ans = 0;
	RE(i, 0, 31) d[i] = do[i];
	RE(i, 0, 31){
		if((b<<i)&a){
			int t = chk(b<<i, i);
			if(t==0) return -1;
			ans += t;
		}
	}
}

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	RE(i, 0, n){
		cin >> a;
		do[bcnt(a)]++;
	}
	RE(i, 0, q){
		cin >> b;
		cout << cnt(b) << '\n';
	}
}

//21:23 03-07-2018
