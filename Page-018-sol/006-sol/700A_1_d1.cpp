//14:59 21-01-2019 to 15:14 21-01-2019 and 18:30 22-01-2019 to 19:20 22-01-2019
//23:54 22-01-2019
//23:59 22-01-2019

#include<iostream>
#include<iomanip>

using namespace std;

int n, l, k, g;
long double v1, v2;

main(){
cin >> n >> l >> v1 >> v2 >> k;
g = (n+k-1)/k;
cout << fixed << setprecision(10) << (l*(2*g*v2-v2+v1))/(v2*(2*g*v1+v2-v1)) << '\n';
}

//23:57 22-01-2019
//00:00 23-01-2019
//00:02 23-01-2019
