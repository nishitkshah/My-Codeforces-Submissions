//18:53 31-05-2018
//18:54 31-05-2018
//19:01 31-05-2018

#include<iostream>

using namespace std;

main(){
	int n;
	char ch;
	bool pisv=false, cisv=false;
	char v[7] = "aeiouy";
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> ch;
		for(int j=0; j<6; j++){
			if(ch==v[j]) cisv = true;
		}
		cerr << i << " " << cisv << " " << pisv << endl;
		if(!pisv||!cisv) cout << ch;
		pisv = cisv;
		cisv = false;
	}
	cout << "\n";
}

//18:59 31-05-2018
//19:09 31-05-2018
