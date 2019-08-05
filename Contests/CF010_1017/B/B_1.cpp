//19:44 08-08-2018
//19:57 08-08-2018

#include<iostream>
#include<string>

using namespace std;

main(){
	int n;
	string sa, sb;
	cin >> n >> sa >> sb;
	int cnt[2][2] = {0};
	for(int i=0; i<n; i++){
		cnt[sa[i]-'0'][sb[i]-'0']++;
	}
	cout << (cnt[0][0]+cnt[0][1])*(cnt[1][0]+cnt[1][1]) << '\n';
}

//20:00 08-08-2018
