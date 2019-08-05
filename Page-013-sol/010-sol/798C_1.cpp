//22:31 17-10-2018 - referred to Editorial
//22:42 17-10-2018

#include<iostream>

using namespace std;

#define N_ 100000

int gcd(int a, int b){
	int r = a%b;
	if(!r) return b;
	return gcd(b, r);
}

int n, a[N_], g, mv=0, sm=0;

main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	g = a[0];
	for(int i=0; i<n; i++) g = gcd(a[i], g);
	mv = 0, sm = 0;
	if(g==1){
		for(int i=0; i<n; i++){
			a[i] = a[i]%2;
			if(a[i]) sm++;
			else{
				mv += (sm+1)/2;
				sm = 0;
			}
		}
		mv += (sm+1)/2;
	}
	cout << "YES\n" << mv << '\n';
}

//22:57 17-10-2018
//22:59 17-10-2018
