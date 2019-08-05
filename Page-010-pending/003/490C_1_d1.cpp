//17:09 06-08-2018
//17:17 06-08-2018
//19:31 06-08-2018

#include<iostream>
#include<string>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAXN 1000010

string s;
int n, a, b, f[MAXN], e[MAXN];
long long d=1LL;

main(){
	cin >> s >> a >> b;
	n = s.size();
	f[0] = (s[0]-'0') % a;
	RE(i, 1, n){
		f[i] = ((10*f[i-1]) + (s[i]-'0')) % a;
	}
	e[n-1] = (s[n-1]-'0') % b;
	for(int i=n-2; i>=0; i--){
		d = (d*10)%b;
		f[i] = (d*(s[i]-'0') + (e[i+1])) % b;
	}
	int p = -1;
	if(s[0]!='0'){
		RE(i, 0, n-1){
			if( f[i]==e[i+1] && s[i+1]!=0 ){
				p = i;
				break;
			}
		}
	}
	if(p!=-1){
		cout << "YES\n";
		cout << s.substr(0, p+1) << '\n';
		cout << s.substr(p+1) << '\n';
	}else{
		cout << "NO\n";
	}
}

//17:42 06-08-2018
//19:33 06-08-2018
//19:34 06-08-2018
