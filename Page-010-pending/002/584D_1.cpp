//12:03 23-07-2018 to 12:28 23-07-2018
//15:59 23-07-2018

#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

int sv[10001]={0}, primes[10000], pc=0;

void sieve(){
	sv[0] = sv[1] = 1;
	RE(i, 2, 10001){
		if(!sv[i]){
			primes[pc++] = i;
			for(int j=i; (i*j)<10001; j++) sv[i*j] = i;
		}
	}
}

long long pow(long long a, int p, int m){
	long long r = 1LL;
	while(p){
		if(p&1) r = (r*a)%m;
		a = (a*a)%m;
		p >>= 2;
	}
	return r;
}

bool rm_test(int n, long long a){
	int p = n-1;
	while(p%2==0) p >>= 1;
	long long pw = pow(a, p, n);
	if(pw==(n-1)) return true;
	while(p<(n-1)){
		pw = (pw*pw)%n;
		p = 2*p;
		if(pw==1) return false;
		if(pw==(n-1)) return true;
	}
	return false;
}

bool isPrime(int n){
	if(n==2) return true;
	if(n%2==0) return false;
	return rm_test(n, 2)&&rm_test(n, 7)&&rm_test(n, 61);
}

main(){
	sieve();
	
	int n;
	cin >> n;
	if(n<9){
		cout << "1\n" << n << '\n';
		return 0;
	}
	cout << "3\n3";
	n -= 3;
	RE(i, 0, pc)
		if(isPrime(n-primes[i])){
			cout << ' ' << primes[i] << ' ' << n-primes[i] << '\n';
			break;
		}
}

//16:38 23-07-2018