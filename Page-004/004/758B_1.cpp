//18:42 31-05-2018
//18:44 31-05-2018

#include<iostream>
#include<map>
#include<string>

using namespace std;

main(){
	string s;
	map<char, int> m;
	int c[4] = {0};
	char ch[5] = "RBYG";
	cin >> s;
	for(int i=0; i<s.size(); i++)
		if(s[i]=='!') c[i%4]++;
		else m[s[i]] = i%4;
	for(int i=0; i<4; i++){
		if(i) cout << " ";
		cout << c[m[ch[i]]];
	}
	cout << "\n";
}

//18:50 31-05-2018
//18:51 31-05-2018
