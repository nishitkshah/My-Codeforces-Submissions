//21:11 04-01-2019 to 21:25 04-01-2019 and 21:34 04-01-2019 to 21:50 04-01-2019
//22:37 04-01-2019 - Continued after 1097D_1.cpp

#include<iostream>
#include<vector>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define P_ 32000000
#define MD 1000000007

long long n, k;
int pl, p[P_]={0};
vector<long long> pr;

void sieve(){
p[0] = p[1] = 1;
RE(i, 2, P_){
	if(p[i]) continue
	if( ((long long)i)*i >= P_) break;
	RE(j, i, P_){
		if( ((long long)i)*j >= P_) break;
		p[i*j] = 1;
	}
}
sort(f.begin(), f.end());
fl = f.size();
}

int pow(long long v, int p=MD-2){
long long rem = 1LL;
int a = v%MD;
while(p){
	if(p&1){
		rem *= a;
		rem %= MD;
	}
	p = p>>1;
	a *= a;
	a %= MD;
}
return (int)rem;
}

main(){
sieve();

}

//22:55 04-01-2019
