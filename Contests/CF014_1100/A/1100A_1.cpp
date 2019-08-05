//20:05 13-01-2019
//20:09 13-01-2019

#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

int n, k, dmx=-1, cd=0, a[100];

main(){
cin >> n >> k;
RE(i, 1, n+1) cin >> a[i];
RE(b, 0, k){
	cd = 0;
	RE(i, 1, n+1)
		if((i%k) != b)
			cd += a[i];
	if(cd<0) cd = -cd;
	if(dmx<cd) dmx = cd;
}
cout << dmx;
}

//20:19 13-01-2019
//20:21 13-01-2019
