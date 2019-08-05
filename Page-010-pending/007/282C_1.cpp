//19:27 07-08-2018
//19:37 07-08-2018

#include<iostream>
#include<string>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

string s[2];
int n;

bool all_zeroes(int ind){
	RE(i, 0, n)
		if(s[ind][i]!='0')
			return true;
	return false;
}

main(){
	cin >> s[0] >> s[1];
	if(s[0].size()!=s[1].size()){
		cout << "NO\n";
		return 0;
	}
	n = s[0].size();
	if(all_zeroes(0)==all_zeroes(1))
		cout << "YES\n";
	else
		cout << "NO\n";
}

//19:43 07-08-2018
//19:44 07-08-2018
