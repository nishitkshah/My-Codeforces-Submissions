//00:02 17-02-2019
//00:08 17-02-2019
//00:18 17-02-2019
//00:24 17-02-2019 - Copied failure function from 432D_1_d1.cpp

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>
#include<string>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 5005

int n, f[N_];
string s;
char c[N_];

void calc_f(){
f[0] = -1, f[1] = 0;
RE(i, 2, n+1){
	int ml = f[i-1];
	while(ml>=0 && s[ml] != s[i-1]) ml = f[ml];
	f[i] = ml+1; 
}
}

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
n = s.size();
calc_f();
if(n%2){
	m = n/2;
	RE(k, 0, ((m-2)/5)+1){
		if(f[4*k+2]>=(2*k+1)&&f[m+k]>=(2*k+1)){
			ans = 1;
		}
	}
}
if(ans<3)
	cout << ans << '\n';
else
	cout << "Impossible\n";
}

//00:17 17-02-2019
//00:18 17-02-2019
//00:34 17-02-2019
//00:34 17-02-2019
