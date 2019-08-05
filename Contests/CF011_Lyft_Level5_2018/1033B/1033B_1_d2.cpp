//23:12 07-10-2018
//23:34 07-10-2018
//23:47 07-10-2018
//23:59 07-10-2018

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
			for(long long j=((long long)i)*i; j<MAXN; j+=i){
				//if(i>40000) cout << i << " " << j << endl;
				b[(int)j] = 1;
			}
			//if(i<1000) cerr << i << endl;
			p.push_back(i);
		}
	}
}

void solve(){
	long long a, b;
	cin >> a >> b;
	if((a-b)!=1){
		cout << "NO\n";
//		cout << "NO1\n";
		return;
	}
	a += b;
	RE(i, 0, p.size())
		if(a==p[i]){
			cout << "YES\n";
			return;
		}
	cout << "NO\n";
}

main(){
//	cout << "c\n";
	sieve();
	int t;
	cin >> t;
	RE(i, 0, t) solve();
}

//23:45 07-10-2018
//23:58 07-10-2018
//00:00 08-10-2018
//00:01 08-10-2018
