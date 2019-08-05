#include<iostream>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int n, cnt;
char c;

int main(){
	ios::sync_with_stdio(0);
	cin >> n;
	cnt = 0;
	cin >> c;
	while((c!='w')&&(c!='m')) cin >> c;
	if(c=='w'){
		n--;
		int wk = 4;
		REP(i, 0, 365)
			if(((wk+i)%7)==n) cnt++;
		cout << cnt;
	}else{
		if(n<=29) cout << 12;
		else if(n==30) cout << 11;
		else if(n==31) cout << 7;
		else cout << 0;
	}
	return 0;
}
