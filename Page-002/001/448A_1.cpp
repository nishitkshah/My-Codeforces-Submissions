//09:59 30-05-2018
//10:02 30-05-2018

#include<iostream>

using namespace std;

main(){
	int a[3], b[3], as, bs, r, n;
	for(int i=0; i<3; i++){
		cin >> a[i];
		as += a[i];
	}
	for(int i=0; i<3; i++){
		cin >> b[i];
		bs += b[i];
	}
	cin >> n;
	r = (as+4)/5 + (bs+9)/10;
	if(r>n) cout << "NO\n";
	else cout << "YES\n";
}

//10:07 30-05-2018
//10:09 30-05-2018
