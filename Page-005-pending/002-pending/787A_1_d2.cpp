//18:04 27-06-2018
//18:13 27-06-2018
//18:26 27-06-2018
//19:33 27-06-2018

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
	int a, b, c, d, g, p, x, y, xr, yr, k;
	cin >> a >> b >> c >> d;
	if(a<c){
		int e, f;
		e = c; f = d;
		c = a; d = b;
		a = e; b = f;
	}
	g = gcd(max(a, c), min(a, c));
	p = abs(d-b)/g;
	if(abs(d-b)%g!=0){
		cout << -1 << "\n";
		return 0;
	}
	x = p*x1;
	y = p*y1;
	xr = ((x%c)+c)%c;
	yr = ((y%a)+a)%a;
	k = max(abs(x+xr)/c, abs(y+yr)/a);
	x += k*c;
	y += k*a;
	cout << x+b << "\n";
	return 0;
}

//18:25 27-06-2018
//18:32 27-06-2018
//19:45 27-06-2018
