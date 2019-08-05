//18:04 27-06-2018
//18:13 27-06-2018

#include<iostream>
#include<algorithm>

using namespace std;

int x1=1, y1=0, x2=0, y2=1;

int gcd(int a, int b){
	if(b==0) return a;
	int r, x3, y3;
	r = a%b;
	x3 = x1-(a/b)*x2;
	y3 = y1-(a/b)*y2;
	x1 = x2;
	y1 = y2;
	x2 = x3;
	y2 = y3;
	return gcd(b, r);
}

int main(){
	int a, b, c, d, g, p;
	cin >> a >> b >> c >> d;
	g = gcd(max(a, c), min(a, c));
	p = abs(d-b)/g;
	if(abs(d-b)%g!=0){
		cout << -1 << "\n";
		return 0;
	}
	cout << max(a, c)*abs(x1)*p+(a>c ? b : d) << "\n";
	return 0;
}

//18:25 27-06-2018
