//17:48 28-06-2018
//17:50 28-06-2018

#include<iostream>
#include<algorithm>

using namespace std;

main(){
	int n, m, a, b, k;
	cin >> n >> m >> a >> b;
	k = n/m;
	cout << min((m*(k+1)-n)*a, (n-m*k)*b) << "\n";
}

//17:53 28-06-2018
//17:54 28-06-2018
