//14:55 19-01-2019
//14:59 19-01-2019

#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define PI 3.141592653589793238462643383279502L

int n;
long long px, py, sx, sy, d, mx=0LL, mn=100000000000000000LL;

main(){
cin >> n >> px >> py;
RE(i, 0, n){
	cin >> sx >> sy;
	d = (px-sx)*(px-sx)+(py-sy)*(py-sy);
	mx = max(mx, d);
	mn = min(mn, d);
}
cout << fixed << setprecision(9) << PI*(mx-mn) << '\n';
}

//15:06 19-01-2019
//15:07 19-01-2019
