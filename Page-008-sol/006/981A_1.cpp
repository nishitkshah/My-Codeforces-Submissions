//16:44 02-07-2018
//16:51 02-07-2018

#include<iostream>
#include<string>

using namespace std;

string s;
int n;

bool isPal(int n){
	for(int i=0; i<n/2; i++)
		if(s[i]!=s[n-1-i]) return false;
	return true;
}

main(){
	cin >> s;
	n = s.size();
	if(!isPal(n)) cout << n << '\n';
	else if(!isPal(n-1)) cout << n-1 << '\n';
	else cout << "0\n";
}

//16:56 02-07-2018
//16:57 02-07-2018
