//20:24 29-06-2018
//20:30 29-06-2018

#include<iostream>
#include<string>

using namespace std;

main(){
	int n;
	string s;
	cin >> n >> s;
	int ans=0;
	for(int i=0; i<n; i++)
		if(s[i]=='<') ans++;
		else break;
	for(int i=n-1; i>=0; i--)
		if(s[i]=='>') ans++;
		else break;
	cout << ans << '\n';
}

//20:33 29-06-2018
//20:35 29-06-2018
