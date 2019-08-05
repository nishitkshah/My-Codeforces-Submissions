//12:23 28-06-2018
//12:25 28-06-2018

#include<iostream>
#include<algorithm>

using namespace std;

int cnt[1000] = {0};

main(){
	int n, m, c, mn=10000000;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		cin >> c;
		c--;
		cnt[c]++;
	}
	for(int i=0; i<n; i++) mn = min(mn, cnt[i]);
	cout << mn << "\n";
}

//12:29 28-06-2018
//12:30 28-06-2018
