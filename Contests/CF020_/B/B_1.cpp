//22:48 04-05-2019
//22:56 04-05-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

int n, m, a[52][52]={0}, b[52][52]={0};

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> m;
RE(i, 1, n+1)
	RE(j, 1, m+1) cin >> a[i][j];
RE(i, 1, n+1)
	RE(j, 1, m+1) cin >> b[i][j];
RE(i, 1, n+1)
	RE(j, 1, m+1)
		if(a[i][j]>b[i][j]) swap(a[i][j], b[i][j]);
bool val = true;
RE(i, 1, n+1)
	RE(j, 1, m+1){
		if(a[i][j]>=a[i-1][j] || a[i][j]>=a[i][j-1])
			val = false;
		if(b[i][j]>=b[i-1][j] || b[i][j]>=b[i][j-1])
			val = false;
	}
if(val) cout << "Possible\n";
else cout << "Impossible\n";
}

//23:02 04-05-2019
