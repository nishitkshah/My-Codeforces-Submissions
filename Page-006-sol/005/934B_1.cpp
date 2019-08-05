//08:27 29-06-2018
//08:31 29-06-2018

#include<iostream>

using namespace std;

main(){
	int k;
	cin >> k;
	if(k>(18*2)){
		cout << "-1\n";
		return 0;
	}
	for(int i=0; i<(k/2); i++) cout << '8';
	if(k%2) cout << '4';
	cout << '\n';
}

//08:35 29-06-2018
//08:36 29-06-2018
