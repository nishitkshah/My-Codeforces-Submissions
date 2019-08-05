//17:46 27-06-2018
//17:51 27-06-2018
//17:59 27-06-2018

#include<iostream>
#include<string>

using namespace std;

int main(){
	int n, m, mn=10000, mnp=0;
	string s, t;
	cin >> n >> m >> s >> t;
	for(int i=0; i<(m-n+1); i++){
		int cnt = 0;
		for(int j=0; j<n; j++){
			if(t[i+j]!=s[j]) cnt++;
		}
		if(cnt<mn){
			mn = cnt;
			mnp = i;
		}
	}
	cout << mn << "\n";
	for(int i=0; i<n; i++){
		if(s[i]!=t[i+mnp]) cout << i+1 << " ";
	}
	cout << "\n";
	return 0;
}

//17:57 27-06-2018
//18:02 27-06-2018
//18:03 27-06-2018 - submitted
