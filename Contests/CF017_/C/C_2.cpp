//19:58 13-04-2019
//20:02 13-04-2019
//20:07 13-04-2019
//20:28 13-04-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 300010

int n, dpl[N_]={0}, dpr[N_]={0};
string s;
bool fail = false;

int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> s;
if(s[0]=='?') s[0] = '(';
if(s[n-1]=='?') s[n-1] = ')';
if(s[0]==')' || s[n-1]=='(' || n%2) fail = true;
RE(i, 1, n-1){
	int co=0, cc=0, cq=0;
	switch(s[i]){
		case '(': co++;
			break;
		case ')': cc++;
			break;
		case '?': cq++;
			break;
	}
	dpl[i] = co+cq-cc;
	if(dpl[i]<0) fail = true;
}
for(int i=n-2; i>0; i--){
	int co=0, cc=0, cq=0;
	switch(s[i]){
		case '(': co++;
			break;
		case ')': cc++;
			break;
		case '?': cq++;
			break;
	}
	dpr[i] = cc+cq-co;
	if(dpr[i]<0) fail = true;
}
if(fail){
	cout << ":(\n";
	return 0;
}
int co=0, cc=0, cq=0, h=(n-2)/2;
RE(i, 1, n-1)
	switch(s[i]){
		case '(': co++;
			break;
		case ')': cc++;
			break;
		case '?': cq++;
			break;
	}
co = h-co;
cc = h-cc;
if(co<0 || cc<0) fail = true;
RE(i, 1, n-1){
	if(s[i]=='?'){
		if(co){
			s[i] = '(';
			co--;
		}else{
			s[i] = ')';
			cc--;
		}
	}
}
if(!fail)
	cout << s << '\n';
else
	cout << ":(\n";
return 0;
}

//20:06 13-04-2019
//20:11 13-04-2019
//21:03 13-04-2019
