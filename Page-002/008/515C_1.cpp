//13:04 30-05-2018
//13:21 30-05-2018

#include<iostream>
#include<string>

using namespace std;

int f[10] = {{0}, {0}, {0}, {0}, {3,2,2}, {0}, {5,3}, {0}, {7,2,2,2}, {7,3,3,2}}

main(){
	int n, ct[10]={0}, t;
	string s;
	cin >> s;
	for(int i=0; i<n; i++) ct[s[i]-'0']++;
	for(int i=0; i<10; i++){
		if(f[i][0]){
			t = ct[i];
			ct[i] = 0;
			for(int j=0; j<4; j++){
				ct[f[i][j]] += t;
			}
		}
	}
	ct[0] = ct[1] = 0;
	for(int i=9; i>1; i--)
		for(int j=0; j<ct[i]; j++) cout << i;
	cout << "\n";
}

//13:30 30-05-2018
