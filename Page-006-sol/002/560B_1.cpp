//19:54 28-06-2018
//20:05 28-06-2018

#include<iostream>

using namespace std;

bool fits(int x, int y, int xi, int yi){
	if(xi<=x&&yi<=y) return true;
	return false;
}

main(){
	int a1, b1, a2, b2, a3, b3;
	cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
	bool small = true;
	if(fits(a1, b1, a2, b2)){
		if(fits(a1-a2, b1, a3, b3) ||
			fits(a1-a2, b1, b3, a3) ||
			fits(a1, b1-b2, a3, b3) ||
			fits(a1, b1-b2, b3, a3)
		)
			small = false;
	}else if(fits(a1, b1, b2, a2)){
		if(fits(a1-b2, b1, a3, b3) ||
			fits(a1-b2, b1, b3, a3) ||
			fits(a1, b1-a2, a3, b3) ||
			fits(a1, b1-a2, b3, a3)
		)
			small = false;
	}
	if(small) cout << "NO\n";
	else cout << "YES\n";
}

//20:14 28-06-2018
//20:15 28-06-2018
