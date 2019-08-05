#include<iostream>
#include<algorithm>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)
#define MAX 200001

int n, o[MAX], s[MAX];

int main(){
	ios::sync_with_stdio(0);
	cin >> n;
	REP(i, 0, n) cin >> o[i];
	REP(i, 0, n) s[o[i]] = i;
	long long ans = 0;
	REP(i, 1, n) ans += abs(s[i]-s[i-1]);
	cout << ans;
	REP(i, 0, n) cout << s[i] << " ";
	return 0;
}
