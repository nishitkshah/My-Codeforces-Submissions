//20:33 08-08-2018
//20:43 08-08-2018
//20:52 08-08-2018

#include<iostream>
#include<algorithm>

using namespace std;

main(){
	int n;
	cin >> n;
	for(int i=1; i<n; i+=2){
		if(i!=1) cout << ' ';
		cout << i+1 << ' ' << i;
	}
	if(n%2) cout << ' ' << n;
	cout << '\n';
}

//20:48 08-08-2018
//20:53 08-08-2018
//20:55 08-08-2018
