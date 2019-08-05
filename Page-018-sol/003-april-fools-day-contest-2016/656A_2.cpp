//14:02 19-01-2019
//14:03 19-01-2019
//14:10 19-01-2019 - started 656A_2.cpp

#include<iostream>

using namespace std;

main(){
int n;
long long ans = 1LL;
cin >> n;
if(n>=13){
	ans = 8092;
	n -= 13;
}
cout << (ans<<n) << '\n';
}

//14:04 19-01-2019
//14:12 19-01-2019
//14:12 19-01-2019
