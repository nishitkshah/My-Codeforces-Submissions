//21:11 04-01-2019 to 21:25 04-01-2019 and 21:34 04-01-2019 to 21:50 04-01-2019
//21:52 04-01-2019

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define ONEe8 100000000
#define ONEe6 1000000
#define MD 1000000007

long long n, k;
vector<long long> f;
vector<long long> ff[ONEe6];
vector<int> dp[ONEe6];
int fl;

void factorize(){
RE(i, 1, ONEe8){
	if( ((long long)i)*i > n) break;
	if(n%i==0){
		f.push_back(i);
		if((n/i)!=i)
			f.push_back(n/i);
	}
}
sort(f.begin(), f.end());
fl = f.size();
RE(i, 0, fl){
	RE(j, 0, i)
		if(f[i]%f[j]==0)
			ff[i].push_back(f[j]);
	ff[i].push_back(f[i]);
}
}

int inv(long long v, int p=MD){
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
cin >> n >> k;
factorize();
//for(auto v: f) cerr << v << ' ';
RE(i, 0, k+1) dp[0].push_back(1);
RE(i, 1, fl) dp[i].push_back(f[i]);
RE(i, 1, fl){
	RE(j, 0, k){
		
	}
}

}

//22:37 04-01-2019 - left as inefficient
