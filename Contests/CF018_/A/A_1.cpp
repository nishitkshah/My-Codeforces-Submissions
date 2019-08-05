//21:00 18-04-2019
//21:06 18-04-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

int n;
string s, t="ACTG";

int ops(int p){
int ans = 0;
RE(i, 0, 4){
	int d = (s[p+i]-t[i]+26)%26;
	ans += min(d, 26-d);
}
return ans;
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> s;
int ans = 27*4;
RE(i, 0, n-3){
	ans = min(ans, ops(i));
}
cout << ans << '\n';
}

//21:13 18-04-2019
//21:15 18-04-2019
