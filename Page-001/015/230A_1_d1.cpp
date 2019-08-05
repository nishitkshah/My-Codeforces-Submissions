//17:43 16-05-2018
//17:46 16-05-2018
//17:52 16-05-2018

#include<iostream>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)
int s, n, x[1010], y[1010];
int main(){
	cin >> s >> n;
	REP(i, 0, n) cin >> x[i] >> y[i+1];
	y[0] = s;
	REP(i, 0, n) y[i+1] += y[i];
	REP(i, 0, n){
		if(x[i]>=y[i]){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}

//17:52 16-05-2018
//17:53 16-05-2018
//17:54 16-05-2018
