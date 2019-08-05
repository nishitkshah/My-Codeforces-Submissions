//20:15 04-01-2019
//20:17 04-01-2019

#include<iostream>
#include<string>

using namespace std;

main(){
string a, h;
cin >> a;
for(int i=0; i<5; i++){
	cin >> h;
	if(a[0]==h[0] || a[1]==h[1]){
		cout << "YES\n";
		return 0;
	}
}
cout << "NO\n";
}

//20:19 04-01-2019
//20:20 04-01-2019
