//16:07 02-07-2018
//16:12 02-07-2018

#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

#define MAX 100000
#define RE(a, b, c) for(int a=(b); a<(c); a++)

int k, n, m;
string s;
unordered_map<string, int> m;
int c[MAX];
int k[MAX];
int mc[MAX];

main(){
	cin >> n >> k >> m;
	RE(i, 0, n){
		cin >> s;
		m[s] = i;
	}
	RE(i, 0, n) cin >> c[i];
	RE(i, 0, k){
		int x, a, mn=MAX+1;
		cin >> x;
		REP(i, 0, x){
			cin >> a;
			a--;
			k[a] = i;
			mn = min(mn, c[a]);
		}
		mc[i] = mn;
	}
	int sm = 0;
	RE(i, 0, m){
		cin >> s;
		sm += c[k[m[s]]];
	}
	cout << sm << '\n';
}

//16:22 02-07-2018
