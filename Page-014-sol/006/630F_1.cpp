//19:14 20-10-2018
//19:22 20-10-2018

#include<iostream>

using namespace std;

main(){
long long n, ans=1LL, p5=1LL, p6=1LL, p7=1LL;
cin >> n;
p5 = ( n*(n-1)*(n-2)*(n-3)*(n-4) ) / (5*4*3*2);
p6 = (p5*(n-5)) / 6;
p7 = (p6*(n-6)) / 7;
cout << p5+p6+p7 << '\n';
}

//19:27 20-10-2018
//19:28 20-10-2018
