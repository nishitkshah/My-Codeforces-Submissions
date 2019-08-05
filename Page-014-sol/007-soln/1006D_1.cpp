//16:26 21-10-2018 to 16:55 21-10-2018
//16:59 21-10-2018

#include<iostream>
#include<string>

using namespace std;
#define RE(a, b, c) for(int a=(b); a<(c); a++)

int cnt(char a1, char a2, char b1, char b2){
	if( (a1==b1 && a2==b2) ||
		(a1==b2 && a2==b1) ||
		(a1==a2 && b1==b2))
			return 0;
	if( (a1==b1) ||
		(a1==b2) ||
		(a2==b1) ||
		(a2==b2) ||
		(b1==b2))
			return 1;
	return 2;
}

main(){
int n;
string a, b;
cin >> n >> a >> b;
int ans = 0;
RE(i, 0, n/2)
	ans += cnt(a[i], a[n-i-1], b[i], b[n-i-1]);
if(n%2)
	if(a[n/2]!=b[n/2]) ans++;
cout << ans << '\n';
}

//17:15 21-10-2018
//17:25 21-10-2018
