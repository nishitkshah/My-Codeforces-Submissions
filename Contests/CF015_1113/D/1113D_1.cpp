//00:02 17-02-2019
//00:08 17-02-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>
#include<string>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 5005

int n;
string s;
char c[N_];

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> s;
n = s.size();
RE(i, 0, n) c[i] = s[i];
int ans = 3, m;
if(n%2==0){
	RE(i, 0, n/2)
		if(c[i]!=c[0])
			ans = 1;
	m = n/2;
	c[m] = s[0];
	RE(i, m+1, n+1)
		c[i] = s[i-1];
	n++;
}
m = n/2;
RE(i, 0, m)
	if(c[i]!=c[0])
		ans = min(ans, 2);
cout << ans << '\n';
}

//00:17 17-02-2019
