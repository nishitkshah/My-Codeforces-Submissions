//19:57 10-03-2019 to 20:19 10-03-2019 - read Editorial (spent a lot of unrecorded time)
//21:02 12-03-2019

#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 1000000001
#define UP 50

int n, dp[UP][UP];
long long ans=0LL;

main(){
cin >> n;
RE(i, 0, UP)
	RE(j, 0, UP){
		dp[i][j] = 1;
		RE(ip, 0, UP)
			RE(jp, 0, UP){
				int s=i*4+j*9, sp=ip*4+jp*9;
				if(sp<s && (sp%(UP-1)) == (s%(UP-1)))
					dp[i][j] = 0;
			}
	}
RE(i, 0, min(8, n))
	for(int j=0; (i+j)<=n; j++)
		if(dp[i][j])
			ans += n-i-j;
cout << ans << '\n';
}

//21:12 12-03-2019
