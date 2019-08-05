//08:40 25-10-2018
//08:49 25-10-2018

#include<iostream>

using namespace std;

int n, k, mxops;

main(){
cin >> n >> k;
mxops = (n*(n-1))/2;
if(mxops>k)
	for(int i=0; i<n; i++)
		cout << "0 " << i << '\n';
else
	cout << "no solution\n";
}

//08:52 25-10-2018
//08:56 25-10-2018
