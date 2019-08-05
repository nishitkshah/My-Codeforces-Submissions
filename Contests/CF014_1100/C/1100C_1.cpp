//20:38 13-01-2019
//20:50 13-01-2019

#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

#define PI 3.14159265358979323846264338327L

int n;
long double r, R, alpha, sin_alpha;

main(){
cin >> n >> r;
alpha = PI/n;
sin_alpha = sin(alpha);
R = sin_alpha*r/(1-sin_alpha);
cout << std::fixed << std::setprecision(10);
cout << R << '\n';
}

//20:57 13-01-2019
//20:58 13-01-2019
