//12:20 18-08-2018
//12:35 18-08-2018

#include<iostream>
#include<string>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAX 100001

main(){

int n, k, c[26]={0}, clen=0, sr[MAX]={0};
char v2c[27];
string s;
cin >> n >> k >> s;

RE(i, 0, n) c[s[i]-'a'] = 1;
RE(i, 0, 26)
	if(c[i]){
		clen++;
		c[i] = clen;
		v2c[clen] = 'a'+i;
	}

string t(k, v2c[1]);
RE(i, 0, n){
	sr[i] = c[s[i]-'a'];
}

int carry = 1;	//Need to add 1
for(int i=(k-1); i>=0; i--){
	sr[i] += carry;
	carry = sr[i]/(clen+1);
	sr[i] = sr[i]%(clen+1);
	if(sr[i]==0) sr[i] = 1;
	t[i] = v2c[sr[i]];
}
//Answer exists - carry will be 0 now

cout << t << '\n';
}

//12:52 18-08-2018
//13:00 18-08-2018
