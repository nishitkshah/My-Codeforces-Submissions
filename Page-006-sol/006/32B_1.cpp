//08:37 29-06-2018
//08:39 29-06-2018

#include<iostream>
#include<string>

using namespace std;

main(){
	string s;
	cin >> s;
	bool dash = false;
	int n = s.size();
	for(int i=0; i<n; i++){
		switch(s[i]){
			case '.':
				if(dash) cout << '1';
				else cout << '0';
				dash = false;
				break;
			case '-':
				if(dash) cout << '2';
				dash = !dash;
				break;
		}
	}
	cout << '\n';
}

//08:48 29-06-2018
//08:49 29-06-2018
