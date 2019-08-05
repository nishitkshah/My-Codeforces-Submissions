//10:22 30-05-2018
//10:25 30-05-2018

#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

typedef unordered_map<string, string> mss;

main(){
	int n, m;
	string s1, s2;
	mss mp;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		cin >> s1 >> s2;
		if(s2.size()<s1.size()) mp[s1] = s2;
		else mp[s1] = s1;
	}
	for(int i=0; i<n; i++){
		cin >> s1;
		if(i) cout << " ";
		cout << mp[s1];
	}
	cout << "\n";
}

//10:30 30-05-2018
//10:32 30-05-2018
