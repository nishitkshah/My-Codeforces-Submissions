//18:53 21-10-2018
//19:12 21-10-2018

#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

main(){
int n, a, b, ka=0, kb;
cin >> n >> a >> b;
while(ka<=n && (n-ka*a)%b) ka++;
if(ka>n){
	cout << "-1\n";
	return 0;
}
kb = (n-ka*a)/b;
RE(i, 0, ka){
	int p = i*a;
	RE(j, 0, a){
		if(i || j) cout << ' ';
		cout << p + ( (j+1) % a ) + 1;
	}
}
RE(i, 0, kb){
	int p = i*b + ka*a;
	RE(j, 0, b){
		cout << ' ' << p + ( (j+1) % b ) + 1;
	}
}
cout << '\n';
}

//19:21 21-10-2018
