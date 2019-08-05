//01:08 10-07-2019 to 01:10 10-07-2019
//01:09 11-07-2019
//01:14 11-07-2019

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MD(a, m) (((a%m)+m)%m)

int n, x1, y1, x2, y2;

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n;
RE(i, 0, n){
	cin >> x1 >> y1 >> x2 >> y2;
	cout << 2*MD(x1, 2) + MD(y1, 2) + 1 << '\n';
}
}

//01:12 11-07-2019
//01:14 11-07-2019
//01:18 11-07-2019
