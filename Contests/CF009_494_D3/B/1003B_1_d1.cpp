//20:14 03-07-2018
//20:18 03-07-2018
//20:32 03-07-2018

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define IA(a, i, x, y) for(int i=(x); i<(y); i++) cin >> a[i];

main(){
	int a, b, x, l, s;
	cin >> a >> b >> x;
	string sa="0", sb="1";
	if(a<b){
		swap(a, b);
		swap(sa, sb);
	}
	string st = "";
	l = (x+1)/2;
	s = x/2;
	a -= l;
	b -= l;
	if(x%2==0){
		a--;
	}
	for(int i=0; i<a; i++){
		st += sa;
	}
	for(int i=0; i<l; i++){
		st += sa+sb;
	}
	for(int i=0; i<b; i++){
		st += sb;
	}
	if(x%2==0){
		st += sa;
	}
	cout << st << '\n';
}

//20:30 03-07-2018
//20:33 03-07-2018
//20:33 03-07-2018
