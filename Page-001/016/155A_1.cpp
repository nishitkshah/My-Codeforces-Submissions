//18:29 16-05-2018
//18:31 16-05-2018

#include<iostream>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int n, a[1010], mx, mn, amz=0;

int main(){
	cin >> n;
	REP(i, 0, n) cin >> a[i];
	mx = mn = a[0];
	REP(i, 0, n){
		if(a[i]<mn){
			amz++;
			mn = a[i];
		}
		if(a[i]>mx){
			amz++;
			mx = a[i];
		}
	}
	cout << amz << "\n";
	return 0;
}

//18:35 16-05-2018
//18:36 16-05-2018
