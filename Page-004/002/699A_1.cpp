//12:09 31-05-2018
//12:13 31-05-2018

#include<iostream>
#include<string>
#include<algorithm>

using namespace  std;

const int INF = 1000000001;

main(){
	int n, p[200000], t=INF;
	string s;
	cin >> n >> s;
	cin >> p[0];
	for(int i=1; i<n; i++){
		cin >> p[i];
		if(s[i]=='L'&&s[i-1]=='R'){
			t = min(t, (p[i]-p[i-1])/2);
		}
	}
	if(t==INF) t = -1;
	cout << t << "\n";
}

//12:19 31-05-2018
