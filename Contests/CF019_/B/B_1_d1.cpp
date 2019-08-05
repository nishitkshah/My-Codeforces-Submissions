//20:22 01-05-2019
//20:26 01-05-2019
//21:04 01-05-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

int t, n;
string s;
int conv[] = {1, 3, 0, 2};

bool cmp(char a, char b){
if(a%4!=b%4) return conv[a%4]<conv[b%4];
return a<b;
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> t;
RE(i, 0, t){
	cin >> s;
	sort(s.begin(), s.end(), cmp);
	n = s.size();
	bool val = true;
	RE(i, 0, n-1)
		if(abs((int)s[i]-(int)s[i+1])==1)
			val = false;
	if(val)
		cout << s << '\n';
	else
		cout << "No answer\n";
}
}

//20:31 01-05-2019
//21:08 01-05-2019
