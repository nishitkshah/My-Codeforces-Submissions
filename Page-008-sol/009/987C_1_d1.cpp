//11:12 03-07-2018
//11:20 03-07-2018
//11:39 03-07-2018

#include<iostream>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define IA(a, i, x, y) for(int i=(x); i<(y); i++) cin >> a[i];
#define MAX 3000
#define INF 10000000000000LL

int n, s[MAX];
long long c[MAX], dc[MAX]={0LL}, tc[MAX]={0LL};

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	IA(s, i, 0, n);
	IA(c, i, 0, n);
	RE(i, 1, n){
		dc[i] = INF;
		RE(j, 0, i){
			if(s[j]<s[i])
				dc[i] = min(dc[i], c[i]+c[j]);
		}
	}
	RE(i, 2, n){
		tc[i] = INF;
		RE(j, 1, i){
			if(s[j]<s[i])
				tc[i] = min(tc[i], dc[j]+c[i]);
		}
		if(tc[i]==INF) tc[i] = 0LL;
	}
	long long mn = INF;
	RE(i, 2, n)
		if(tc[i])
			mn = min(mn, tc[i]);
	if(mn==INF) mn = -1LL;
	cout << mn << '\n';
}

//11:37 03-07-2018
//11:40 03-07-2018
//11:40 03-07-2018
