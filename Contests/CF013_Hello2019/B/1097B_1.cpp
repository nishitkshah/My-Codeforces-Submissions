//20:21 04-01-2019
//20:22 04-01-2019

#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 15

int n, a[N_];

int chk(int v){
	if(v<0) v = -v;
	return v%360;
}

int val(int bm){
int sum=0;
RE(i, 0, n){
	if(bm&(1<<i)) sum -= a[i];
	else sum += a[i];
}
return sum;
}

main(){
cin >> n;
RE(i, 0, n) cin >> a[i];
RE(i, 0, 1<<n){
	if(chk(val(i))==0){
		cout << "YES\n";
		return 0;
	}
}
cout << "NO\n";
}

//20:29 04-01-2019
//20:30 04-01-2019
