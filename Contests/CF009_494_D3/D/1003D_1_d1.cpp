//20:56 03-07-2018
//21:06 03-07-2018
//21:24 03-07-2018

#include<iostream>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define IA(a, i, x, y) for(int i=(x); i<(y); i++) cin >> a[i];
#define PA(a, i, x, y) for(int i=(x); i<(y); i++) cerr << a[i] << " "; cerr << '\n';

int n, q, di[31]={0}, a, b, d[31];

int bcnt(int a){
	int b=0;
	while(a){
		b++;
		a = a>>1;
	}
	return b-1;
}

int chk(int b, int p){
	int ans = 0;
	for(int i=p; b&&(i>=0); i--){
		int sub = min(b/(1<<i), d[i]);
		b -= sub*(1<<i);
		d[i] -= sub;
		ans += sub;
	}
	if(b) return 0;
	return ans;
}

int cnt(int a){
	int b = 1, ans = 0;
	RE(i, 0, 31) d[i] = di[i];
	//cerr << "chk: " << chk(8, 3) << " ";
	//cerr << chk(8, 3) << " ";
	//cerr << chk(8, 3) << "\n";
	RE(i, 0, 31){
		if((b<<i)&a){
			int t = chk(b<<i, i);
			if(t==0) return -1;
			ans += t;
		}
	}
	return ans;
}

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	//cerr << "dbg: bcnt(8): " << bcnt(8) << '\n';
	RE(i, 0, n){
		cin >> a;
		di[bcnt(a)]++;
	}
	//PA(di, i, 0, 31);
	RE(i, 0, q){
		cin >> b;
		//cout << "a: " << cnt(b) << '\n';
		cout << cnt(b) << '\n';
	}
}

//21:23 03-07-2018
//21:47 03-07-2018
//21:48 03-07-2018
