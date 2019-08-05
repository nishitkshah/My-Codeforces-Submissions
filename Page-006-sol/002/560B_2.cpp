//20:36 28-06-2018

#include<iostream>
#include<algorithm>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

main(){
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	bool small = true;
	REP(i, 0, 2){
		swap(c, d);
		REP(j, 0, 2){
			swap(e, f);
			if((c+e)<=a && max(d, f)<=b) small = false;
			if(max(c, e)<=a && (d+f)<=b) small = false;
		}
	}
	cout << (small ? "NO\n" : "YES\n");
}

//20:41 28-06-2018
//20:42 28-06-2018
