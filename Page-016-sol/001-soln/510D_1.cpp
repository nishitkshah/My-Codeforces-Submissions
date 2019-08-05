//11:40 03-11-2018 to 12:50 03-11-2018 - read editorial
//19:32 03-11-2018

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 300
#define INF 2000000000
#define C_ 100001

int n, l[N_], c[N_], dp[1<<9], mn=INF;
int cnt, sv[C_]={0};
vector<int> pr;

inline void sieve(){
RE(i, 2, C_)
	if(!sv[i]){
		for(int j=i; j<=((C_-1)/i); j++)
			sv[i*j] = 1;
		pr.push_back(i);
	}
cnt = pr.size();
}

main(){
sieve();
cin >> n;
RE(i, 0, n) cin >> l[i];
RE(i, 0, n) cin >> c[i];
RE(ct, 0, n){
	vector<int> p;
	RE(i, 0, cnt)
		if(!(l[ct]%pr[i]))
			p.push_back(pr[i]);
	int psz = p.size();
	RE(i, 0, 1<<psz) dp[i] = INF;
	dp[(1<<psz) - 1] = c[ct];
	RE(i, 0, n){
		int bmi = 0;
		RE(j, 0, p.size())
			if(!(l[i]%p[j]))
				bmi += 1<<j;
		for(int bm=(1<<psz)-1; bm>=0; bm--){
			int res = bm&bmi;
			dp[res] = min(dp[res], dp[bm]+c[i]);
		}
	}
	mn = min(mn, dp[0]);
}
if(mn>=INF) mn = -1;
cout << mn << '\n';
}

//20:03 03-11-2018
//20:07 03-11-2018
