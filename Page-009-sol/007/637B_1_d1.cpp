//10:54 11-07-2018
//10:58 11-07-2018
//11:10 11-07-2018

#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

#define MAX 200000
#define RE(a, b, c) for(int a=(b); a<(c); a++)

int n, ind[MAX], rl[MAX], p=0;
string s;
unordered_map<string, int> m;
unordered_map<int, string> mr;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	RE(i, 0, n){
		cin >> s;
		if(m.count(s)==0){
			m[s] = p;
			mr[p++] = s;
		}
		ind[m[s]] = i;
		rl[i] = -1;
	}
	RE(i, 0, p) rl[ind[i]] = i;
	for(int i=n-1; i>=0; i--)
		if(rl[i]!=-1) cout << mr[rl[i]] << '\n';
}

//11:09 11-07-2018
//11:19 11-07-2018
//11:20 11-07-2018
