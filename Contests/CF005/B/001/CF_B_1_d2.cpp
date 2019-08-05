#include<iostream>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int main(){
	ios::sync_with_stdio(0);
	unsigned long long n = 1, l, u;
	int cnt = 0;
	cin >> l >> u;
	REP(i, 2, 19){
		n = 2*n+1;
		REP(j, 0, i-1){
			if((l<=(n-(1<<j)))&&((n-(1<<j))<=u)) cnt++;
		}
	}
	cout << cnt;
	return 0;
}
