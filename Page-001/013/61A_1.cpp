//17:20 16-05-2018
//17:22 16-05-2018

#include<iostream>
#include<string>

using namespace std;

int main(){
	string s1, s2;
	int n;
	cin >> s1 >> s2;
	n = s1.size();
	for(int i=0; i<n; i++){
		if(s1[i]!=s2[i]) s1[i] = '1';
		else s1[i] = '0';
	}
	cout << s1 << "\n";
	return 0;
}

//17:24 16-05-2018
//17:26 16-05-2018
