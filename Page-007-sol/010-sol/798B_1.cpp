//15:40 01-07-2018
//15:44 01-07-2018

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int n, mn = 10000000, l;
string s[50], d[50];

int moves(int p, int q){
	int mv = -1;
	REP(m, 0, l){
		bool match = true;
		REP(i, 0, l){
			if(s[p][i]!=d[q][i+m]) match = false;
		}
		if(match){
			mv = m;
			break;
		}
	}
	return mv;
}

main(){
	cin >> n;
	REP(i, 0, n){
		cin >> s[i];
		d[i] = s[i] + s[i];
	}
	l = s[0].size();
	REP(i, 0, n){
		int cnt = 0;
		REP(j, 0, n){
			int mv = moves(i, j);
			if(mv==-1){
				cout << mv << '\n';
				return 0;
			}
			cnt += mv;
		}
		mn = min(mn, cnt);
	}
	cout << mn << '\n';
}

//16:06 01-07-2018
//16:07 01-07-2018
