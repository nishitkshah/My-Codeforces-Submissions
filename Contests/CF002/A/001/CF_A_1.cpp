#include<iostream>
#include<algorithm>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int main(){
	ios::sync_with_stdio(0);
	int mx=0;
	int n, s;
	int f, t;
	cin >> n >> s;
	REP(i, 0, n){
		cin >> f >> t;
		mx = max(mx, max(0, t-s+f));
	}
	cout << s+mx;
	return 0;
}
