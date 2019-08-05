//17:48 28-06-2018
//17:50 28-06-2018
//17:55 28-06-2018

#include<iostream>
#include<algorithm>

using namespace std;

main(){
	long long n, m, a, b, k;
	cin >> n >> m >> a >> b;
	k = n/m;
	cout << min((m*(k+1)-n)*a, (n-m*k)*b) << "\n";
}

//17:53 28-06-2018
//17:56 28-06-2018
//17:56 28-06-2018
