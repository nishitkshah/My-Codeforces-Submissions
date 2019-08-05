//19:16 28-06-2018
//19:18 28-06-2018

#include<iostream>
#include<string>
#include<vector>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

vector<string> g(4);

inline bool cnt(int x, int y){
	if(x==3||y==3) return false;
	int hc=0, dc=0;
	REP(i, x, x+2)
		REP(j, y, y+2)
			if(g[i][j]=='#') hc++;
			else dc++;
	if(hc>2||dc>2) return true;
	return false;
}

main(){
	REP(i, 0, 4) cin >> g[i];
	REP(i, 0, 4)
		REP(j, 0, 4)
			if(cnt(i, j)){
				cout << "YES\n";
				return 0;
			}
	cout << "NO\n";
}

//19:25 28-06-2018
//19:26 28-06-2018
