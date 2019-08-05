//14:02 15-01-2019 - read prob and soln before
//14:18 15-01-2019
//14:36 15-01-2019

#include<iostream>
#include<string>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100000

string s;
int n, f[N_+1]={0}, cnt[N_+1]={0}, flag[N_+1]={0};

void calc_f(){
f[0] = -1, f[1] = 0;
RE(i, 2, n+1){
	int ml = f[i-1];
	while(ml>=0 && s[ml] != s[i-1]) ml = f[ml];
	f[i] = ml+1; 
}
}

main(){
cin >> s;
n = s.size();
calc_f();
//RE(i, 0, n+1) cerr << f[i] << ' ';
//cerr << '\n';
RE(i, 0, n+1) cnt[f[i]]++;
for(int i=n; i>=0; i--)
	if(f[i]>=0)
		cnt[f[i]] += cnt[i];
int l = n, c=0;
while(l>0){
	flag[l] = 1;
	c++;
	l = f[l];
}
cout << c << '\n';
RE(i, 1, n+1)
	if(flag[i])
		cout << i << ' ' << cnt[i]+1 << '\n';
}

//14:35 15-01-2019
//14:50 15-01-2019
//14:52 15-01-2019
