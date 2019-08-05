//09:22 31-05-2018
//09:25 31-05-2018

#include<iostream>
#include<string>

using namespace std;

main(){
	int n, r1, r2;
	string s;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> s >> r1 >> r2;
		if(r1>=2400&&r2>r1){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}

//09:27 31-05-2018
//09:28 31-05-2018
