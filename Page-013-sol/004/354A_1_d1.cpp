//22:23 08-09-2018
//22:26 08-09-2018
//22:37 08-09-2018

#include<iostream>
#include<algorithm>

using namespace std;

main(){
	int n, l, r, ql, qr, w;
	long long dlp=0LL, drp=0LL, dl, dr;
	cin >> n >> l >> r >> ql >> qr;
	for(int i=0; i<n; i++){
		cin >> w;
		dl = min(dlp+w*l+ql, drp+w*l);
		dr = min(dlp+w*r, drp+w*r+qr);
		dlp = dl;
		drp = dr;
		cerr << dl << ' ' << dr << '\n';
	}
	cout << min(dlp, drp);
}

//22:34 08-09-2018
//22:39 08-09-2018
