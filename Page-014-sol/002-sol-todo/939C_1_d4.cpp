//12:34 19-10-2018 to 12:47 19-10-2018
//17:31 19-10-2018
//17:41 19-10-2018
//17:48 19-10-2018
//17:52 19-10-2018
//17:40 20-10-2018

#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100000

int n, a[N_], s, f, sum=0, d, l, r, mx, mxp;

main(){
cin >> n;
RE(i, 0, n) cin >> a[i];
cin >> s >> f;
d = f-s;
RE(i, 0, d) sum += a[i];
l=0, r=d-1, mx=sum, mxp=1;
RE(i, 1, n+1){
	sum -= a[l];
	l++; r++;
	r %= n;
	sum += a[r];
	if(mx<=sum){
		mx = sum;
		mxp = i+1;
	}
}
int mxt = s-mxp+1;
while(mxt<=0) mxt += n;
while(mxt>n) mxt -= n;
cout << mxt << '\n';
}

//17:37 19-10-2018
//17:42 19-10-2018
//17:49 19-10-2018
//17:55 19-10-2018
//17:41 20-10-2018
//17:43 20-10-2018
