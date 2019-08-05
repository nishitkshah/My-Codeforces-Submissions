//22:07 18-10-2018
//22:13 18-10-2018

#include<iostream>

using namespace std;

int dist(int x, int y){
	return x>y ? x-y : y-x;
}

main(){
	int x, y, z, t1, t2, t3;
	cin >> x >> y >> z >> t1 >> t2 >> t3;
	int ts = dist(x, y)*t1;
	int te = dist(z, x)*t2 + 2*t3 + dist(x, y)*t2 + t3;
	if(te>ts) cout << "NO\n";
	else cout << "YES\n";
}

//22:20 18-10-2018
//22:23 18-10-2018
