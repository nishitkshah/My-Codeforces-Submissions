//22:50 24-12-2018
//22:54 24-12-2018

#include<iostream>
#include<string>

using namespace std;

main(){
string s;
cin >> s;
bool root = true;
char p='/';
for(auto c: s){
	if(c!='/'){
		if(p=='/') cout << p;
		cout << c;
		root = false;
	}
	p = c;
}
if(root) cout << '/';
cout << '\n';
}

//23:04 24-12-2018
//23:07 24-12-2018
