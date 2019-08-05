//17:07 01-06-2018
//17:10 01-06-2018

#include<iostream>

using namespace std;

int main(){
	int n, a, sum=0, odd=0;

	cin >> n;

	for(int i=0; i<n; i++){
		cin >> a;
		a = a%2;
		if(a) odd++;
		sum += a;
	}
	sum = sum%2;
	if(!sum&&!odd) cout << "Second\n";
	else cout << "First\n";
}

//17:15 01-06-2018
//17:16 01-06-2018
