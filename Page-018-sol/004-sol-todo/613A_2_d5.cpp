//14:55 19-01-2019
//14:59 19-01-2019
//16:41 19-01-2019 - 613A_2.cpp started
//17:02 19-01-2019 - saw failed testcase
//17:44 19-01-2019 - reffered to editorial and existing solutions
//18:08 19-01-2019
//18:41 19-01-2019
//18:48 19-01-2019 - referred to Wikipedia - https://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line#Line_defined_by_two_points

#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define PI 3.141592653589793238462643383279502L
#define N_ 100001

typedef long double LD;
typedef long long LL;

int n;
LL px, py, sx[N_], sy[N_];
LD d, mx=0.0L, mn=1e16L;

inline LD dis_sq(LL x, LL y){
	return (LD)x*x+y*y;
}

inline LD cross_prod(LD x1, LD y1, LD x2, LD y2){
	long long z = x1*y2-x2*y1;
	return z*z;
}

inline LL scal_prod(LL bx, LL by, LL px, LL py, LL qx, LL qy){
	LL x1=px-bx, x2=qx-bx, y1=py-by, y2=qy-by;
	return x1*x2+y1*y2;
}

inline LD perpdis_sq(LL bx, LL by, LL px, LL py, LL qx, LL qy){
	LL num = (qy-py)*bx - (qx-px)*by + qx*py - qy*px;
	return ((LD)num)*num/dis_sq(qx-px, qy-py);
}

main(){
cin >> n >> px >> py;
RE(i, 0, n)
	cin >> sx[i] >> sy[i];
sx[n] = sx[0], sy[n] = sy[0];
RE(i, 0, n){
	//cerr << i << ":\n";
	d = dis_sq(px-sx[i], py-sy[i]);
	//cerr << d << " " << mx << " " << mn << "\n";
	if(d<0.0L) d = -d;
	mx = max(mx, d);
	mn = min(mn, d);
	if(scal_prod(sx[i], sy[i], sx[i+1], sy[i+1], px, py)>=0LL && scal_prod(sx[i+1], sy[i+1], sx[i], sy[i], px, py)>=0LL){
		//d = cross_prod(sx[i+1]-sx[i], sy[i+1]-sy[i], px-sx[i], py-sy[i])/dis_sq(sx[i+1]-sx[i], sy[i+1]-sy[i]);
		d = perpdis_sq(px, py, sx[i], sy[i], sx[i+1], sy[i+1]);
		//cerr << d << " " << mx << " " << mn << "\n";
		if(d<0.0L) d = -d;
		mx = max(mx, d);
		mn = min(mn, d);
	}
}
//cerr << fixed << setprecision(9) << (mx-mn) << '\n';
cout << fixed << setprecision(9) << PI*(mx-mn) << '\n';
}

//15:06 19-01-2019
//16:58 19-01-2019
//17:03 19-01-2019
//18:08 19-01-2019
//18:16 19-01-2019
//18:42 19-01-2019
//18:54 19-01-2019
//18:56 19-01-2019
