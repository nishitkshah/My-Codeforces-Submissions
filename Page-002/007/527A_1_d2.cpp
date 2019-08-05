//12:52 30-05-2018
//12:55 30-05-2018
//12:58 30-05-2018
//13:00 30-05-2018

#include<iostream>

using namespace std;

main(){
	unsigned long long a, b, c, t=0;
	cin >> a >> b;
	while(a%b){
		t += a/b;
		c = a%b;
		a = b;
		b = c;
	}
	t += a/b;
	cout << t << "\n";
}

//12:57 30-05-2018
//12:58 30-05-2018
//13:00 30-05-2018
//13:03 30-05-2018
