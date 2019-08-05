//19:06 16-05-2018
//19:08 16-05-2018

#include<iostream>

using namespace std;

int main(){
	int n, m;
	char c;
	cin >> n >> m;
	for(int i=0; i<(n*m); i++){
		cin >> c;
		if(c=='C'||c=='M'||c=='Y'){
			cout << "#Color\n";
			return 0;
		}
	}
	cout << "#Black&White\n";
	return 0;
}

//19:11 16-05-2018
//19:12 16-05-2018
