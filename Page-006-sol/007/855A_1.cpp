//08:50 29-06-2018
//08:52 29-06-2018

#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

void ans(int c){
	if(c==1) cout << "YES\n";
	else cout << "NO\n";
}

main(){
	int n;
	string s;
	unordered_set<string> u;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> s;
		ans(u.count(s));
		u.insert(s);
	}
}

//08:57 29-06-2018
//08:58 29-06-2018
