//11:30 19-08-2018 - read solution (editorial)
//12:07 19-08-2018
//20:07 19-08-2018
//20:11 19-08-2018

#include<iostream>
#include<string>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAX 200000

string s;
int n, dp[MAX+1], sl[MAX], im[3]={-1, -1, -1};

main(){
cin >> s;
n = s.size();
dp[0] = 0;
int md = 0;
RE(i, 0, n){
	int num = s[i]-'0';
	md = ( 10*md + num )%3;
	if(im[md]!=-1){
		sl[i] = i-im[md];
	}else{
		if(md==0)
			sl[i] = 1;
		else
			sl[i] = 0;
	}
	im[md] = i;
	if(sl[i])
		dp[i+1] = max(dp[i+1-sl[i]] + 1, dp[i]);
	else
		dp[i+1] = dp[i];
}

cout << dp[n] << '\n';
}

//12:26 19-08-2018
//20:08 19-08-2018
//20:11 19-08-2018
//20:13 19-08-2018
