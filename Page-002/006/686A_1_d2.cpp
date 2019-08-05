//12:37 30-05-2018
//12:40 30-05-2018
//12:46 30-05-2018
//12:49 30-05-2018

#include<iostream>

using namespace std;

main(){
	int n, c=0;
	long long x, d;
	char ch;
	cin >> n >> x;
	for(int i=0; i<n; i++){
		cin >> ch >> d;
		if(ch=='+') x += d;
		else
			if(x<d) c++;
			else x -= d;
	}
	cout << x << " " << c << "\n";
}

//12:44 30-05-2018
//12:46 30-05-2018
//12:50 30-05-2018
