//19:13 16-05-2018
//19:15 16-05-2018

#include<iostream>
#include<string>
#include<vector>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int main(){
	int n;
	vector<string> v;
	cin >> n;
	v.resize(n);
	for(int i=0; i<n; i++)
		cin >> v[i];
	bool found = false;
	REP(i, 0, n){
		if(v[i][0]=='O'&&v[i][1]=='O'){
			v[i][0] = '+';
			v[i][1] = '+';
			found = true;
			break;
		}
		if(v[i][3]=='O'&&v[i][4]=='O'){
			v[i][3] = '+';
			v[i][4] = '+';
			found = true;
			break;
		}
	}
	if(found){
		cout << "YES\n";
		REP(i, 0, n) cout << v[i] << "\n"; 
	}else
		cout << "NO\n";
	return 0;
}

//19:23 16-05-2018
//19:24 16-05-2018
