//16:35 16-05-2018
//16:37 16-05-2018

#include<iostream>
#include<string>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int cnt[4] = {0};

int main(){
	string s;
	cin >> s;
	REP(i, 0, s.size())
		if(s[i]>='1'&&s[i]<='3')
			cnt[s[i]-'0']++;
	int p = 1;
	while(cnt[p]==0) p++;
	cout << p;
	cnt[p]--;
	for(; p<4; ){
		if(cnt[p]==0) p++;
		else{
			cout << "+" << p;
			cnt[p]--;
		}
	}
	cout << "\n";
	return 0;
}

//16:42 16-05-2018
//16:44 16-05-2018
