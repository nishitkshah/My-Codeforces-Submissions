//15:08 01-07-2018
//15:14 01-07-2018
//15:36 01-07-2018

#include<iostream>
#include<string>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int t;
string s;
int f[] = {1, 2, 3, 4, 6, 12};
int ans[6] = {0};
//register int acnt = 0;
int acnt = 0;

inline bool chk(int f){
	int r=f, c=12/f;
	bool win = false;
	for(int j=0; j<c; j++){
		bool all = true;
		for(int i=0; i<r; i++){
			int pos = c*i+j;
			if(s[pos]=='O') all = false;
		}
		win = win || all;
	}
	return win;
}

void solve(){
	acnt = 0;
	cin >> s;
	for(int i=0; i<6; i++){
		if(chk(f[i])){
			ans[acnt] = f[i];
			acnt++;
		}
	}
	cout << acnt;
	for(int i=0; i<acnt; i++)
		cout << " " << ans[i] << 'x' << 12/ans[i];
	cout << '\n';
}

main(){
	cin >> t;
	for(int i=0; i<t; i++) solve();
}

//15:32 01-07-2018
//15:38 01-07-2018
//15:38 01-07-2018
