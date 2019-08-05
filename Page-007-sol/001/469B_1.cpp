//10:04 29-06-2018
//10:29 29-06-2018

#include<iostream>
#include<algorithm>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int m[1001]={0};

void fill(int a, int b, int c, int d){
	if(b<c) return;
	int mn = max(a-d, 0);
	int mx = b-c;
	REP(i, mn, mx+1) m[i] = 1;
}

main(){
	int p, q, l, r;
	int a[50], b[50], c[50], d[50];
	cin >> p >> q >> l >> r;
	REP(i, 0, p) cin >> a[i] >> b[i];
	REP(j, 0, q){
		cin >> c[j] >> d[j];
		REP(i, 0, p){
			fill(a[i], b[i], c[j], d[j]);
		}
	}
	int sum = 0;
	REP(i, l, r+1) sum += m[i];
	cout << sum << '\n';
}

//10:41 29-06-2018
//10:42 29-06-2018
