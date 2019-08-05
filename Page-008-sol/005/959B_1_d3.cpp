//16:07 02-07-2018
//16:12 02-07-2018
//16:24 02-07-2018
//16:28 02-07-2018
//16:32 02-07-2018

#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

#define MAX 100000
#define RE(a, b, c) for(int a=(b); a<(c); a++)

int k, n, m;
string s;
unordered_map<string, int> mp;
int c[MAX];
int g[MAX];
int mc[MAX];

main(){
	cin >> n >> k >> m;
	RE(i, 0, n){
		cin >> s;
		mp[s] = i;
	}
	RE(i, 0, n) cin >> c[i];
	RE(i, 0, k){
		int x, a, mn=MAX+1;
		cin >> x;
		RE(j, 0, x){
			cin >> a;
			a--;
			g[a] = i;
			mn = min(mn, c[a]);
		}
		mc[i] = mn;
		//cerr << "g: " << mn << '\n';
	}
	long long sm = 0LL;
	RE(i, 0, m){
		cin >> s;
		sm += mc[g[mp[s]]];
	}
	cout << sm << '\n';
}

//16:22 02-07-2018
//16:26 02-07-2018
//16:31 02-07-2018
//16:33 02-07-2018
//16:33 02-07-2018
