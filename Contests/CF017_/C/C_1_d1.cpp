//19:58 13-04-2019
//20:02 13-04-2019
//20:07 13-04-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

int n, c=-1;
string s;
bool fail = false;

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> s;
s[0] = '(';
s[n-1] = ')';
RE(i, 0, n){
	//cerr << c << ' ' << s[i] << '\n';
	if(s[i]=='?'){
		if(c>0){
			s[i] = ')';
			c--;
		}else{
			s[i] = '(';
			c++;
		}
	}else if(s[i]=='(') c++;
	else c--;
	if(c<0 && i!=(n-1)) fail = true; 
}
if(c!=-1) fail = true;
//cerr << c << '\n';
if(!fail)
	cout << s << '\n';
else
	cout << ":(\n";
}

//20:06 13-04-2019
//20:11 13-04-2019
//20:12 13-04-2019
