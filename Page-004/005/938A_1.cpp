//18:53 31-05-2018
//18:54 31-05-2018

#include<iostream>

using namespace std;

main(){
	int n;
	char ch;
	bool pisv=false, cisv=false;
	char v[7] = "aeiouy";
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		cisv = false;
		cin >> ch;
		for(int j=0; j<6; j++){
			if(ch==v[i]) cisv = true;
		}
		if(!pisv||!cisv) cout << ch;
		pisv = cisv;
	}
	cout << "\n";
}

//18:59 31-05-2018
//19:00 31-05-2018
