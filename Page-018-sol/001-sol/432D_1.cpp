//14:02 15-01-2019 - read prob and soln before
//14:18 15-01-2019

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
	while(s[ml] != s[i] && ml>0) ml = f[ml];
	f[i] = ml+1; 
}
}

main(){
cin >> s;
n = s.size();
calc_f();
RE(i, 0, n+1) cnt[f[i]]++;
for(int i=n; i>=0; i--)
	if(f[i]>=0)
		cnt[f[i]] += cnt[i];
int l = n;
while(l>0){
	flag[l] = 1;
	l = f[l];
}
RE(i, 1, n+1)
	cout << i << ' ' << cnt[i] << '\n';
}

//14:35 15-01-2019
