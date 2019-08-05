//21:45 02-07-2018
//21:50 02-07-2018
//22:06 02-07-2018
//22:13 02-07-2018

#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAX 200002

int n, k, q, l, r;
long long t[MAX]={0};

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k >> q;
	RE(i, 0, n){
		cin >> l >> r;
		t[l] += 1;
		t[r+1] -= 1;
	}
	RE(i, 1, MAX) t[i] += t[i-1];
	RE(i, 0, MAX) t[i] = (t[i]>=k ? 1 : 0);
	RE(i, 1, MAX) t[i] += t[i-1];
	RE(i, 0, q){
		cin >> l >> r;
		cout << t[r]-t[l-1] << '\n';
	}
}

//22:01 02-07-2018
//22:08 02-07-2018
//22:13 02-07-2018
//22:14 02-07-2018
