//12:34 19-10-2018 to 12:47 19-10-2018
//17:31 19-10-2018

#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100000

int n, a[N_], s, f, sum=0, d, l, r, mx, mxt;

main(){
cin >> n;
RE(i, 0, n) cin >> a[i];
cin >> s >> f;
d = f-s;
RE(i, 0, d) sum += a[i];
l=0, r=d-1, mx=sum, mxt=1;
RE(i, 1, n){
	sum -= a[l];
	l++; r++;
	r %= n;
	sum += a[r];
	if(mx<sum){
		mx = sum;
		mxt = i+1;
	}
}
cout << mxt << '\n';
}

//17:37 19-10-2018
