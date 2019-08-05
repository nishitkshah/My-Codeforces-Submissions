//23:12 07-10-2018
//23:34 07-10-2018

#include<iostream>
#include<vector>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAXN 1000001

int b[MAXN]={0};
vector<int> p;

void sieve(){
	b[0] = b[1] = 1;
	b[2] = 0;
	RE(i, 2, MAXN){
		if(!b[i]){
			for(long long j=i*i; j<MAXN; j+=i)
				b[(int)j] = 1;
			p.push_back(i);
		}
	}
}

void solve(){
	long long a, b;
	cin >> a >> b;
	if((a-b)!=1){
		cout << "NO\n";
		return;
	}
	a += b;
	RE(i, 0, p.size())
		if((a%p[i])==0){
			cout << "NO\n";
			return;
		}
	cout << "YES\n";
}

main(){
	sieve();
	int t;
	cin >> t;
	RE(i, 0, t) solve();
}

//23:45 07-10-2018