//23:17 11-07-2019 to 23:23 11-07-2019 and 23:52 18-07-2019 to 23:57 18-07-2019
//23:57 18-07-2019

#include<bits/stdc++.h>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 1000010

int n, m, a[N_]={0}, dp[N_][3][3][3]={0}, cnt[N_]={0};

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> m;
RE(i, 1, n+1){
	cin >> a[i];
	cnt[a[i]]++;
}
RE(i, 1, n+1)
	RE(cim3, 0, 3)		//C i-3
		RE(cim2, 0, 3)
			RE(cim1, 0, 3)
				RE(ci, 0, 3)
					if(cnt[i] >= (cim2+cim1+ci))
						if(cnt[i+1] >= (cim1+ci))
							if(cnt[i+2] >= (ci))
								dp[i][cim2][cim1][ci] = max(dp[i][cim2][cim1][ci],
									dp[i-1][cim3][cim2][cim1] + ci + (cnt[i]-cim2-cim1-ci)/3);
int mx = 0;
RE(i, 0, 3)
	RE(j, 0, 3)
		RE(k, 0, 3)
			mx = max(mx, dp[n][i][j][k]);
cout << mx << '\n';
}

//00:14 19-07-2019
//00:15 19-07-2019
