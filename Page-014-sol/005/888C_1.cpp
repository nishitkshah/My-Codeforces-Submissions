//18:51 20-10-2018
//18:57 20-10-2018

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

main(){
string s;
cin >> s;
int n, l, r, ans;
n = s.size();
ans = n+1;
for(char c='a'; c<='z'; c++){
	l=0, r=n+1;
	int mx=-1;
	for(int i=0; i<n; i++){
		if(s[i]==c){
			r = i+1;
			mx = max(r-l, mx);
			l = r;
		}
	}
	r = n+1;
	mx = max(r-l, mx);
	ans = min(mx, ans);
}
cout << ans;
}

//19:06 20-10-2018
//19:08 20-10-2018
