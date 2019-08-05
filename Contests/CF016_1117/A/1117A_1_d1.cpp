//21:10 18-02-2019
//21:12 18-02-2019
//21:18 18-02-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100001

int n, a[N_], mx=-1, mxl=0;

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n;
RE(i, 0, n) cin >> a[i];
RE(i, 0, n) mx = max(mx, a[i]);
int l=0;
if(a[0]==mx) l = 1;
mxl = max(mxl, l);
RE(i, 1, n){
	if(a[i]==mx){
		if(a[i]==a[i-1])
			l++;
		else
			l = 1;
	}else
		l = 0;
	mxl = max(mxl, l);
}
cout << mxl << '\n';
}

//21:16 18-02-2019
//21:19 18-02-2019
//21:20 18-02-2019
