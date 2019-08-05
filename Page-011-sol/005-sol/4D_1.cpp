//20:05 13-08-2018
//20:11 13-08-2018

#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

int n, w[5001], h[5001], cnt[5001]={0}, p[5001]={0}, q[5001], pt=0, dp[5001]={0};

bool covers(int i, int j){
	return w[j]<w[i]&&h[j]<h[i];
}

main(){
	cin >> n >> w[0] >> h[0];
	n++;
	RE(i, 1, n) cin >> w[i] >> h[i];
	RE(i, 0, n){
		RE(j, 0, n){
			if(covers(i, j))
				cnt[j]++;
		}
	}
	RE(i, 0, n) if(!cnt[i]) q[pt++] = i, dp[i] = 1, p[i] = 0;
	RE(i, 0, pt){
		RE(j, 0, n){
			if(covers(i, j)){
				cnt[j]--;
				if(!cnt[j]) q[pt++] = j;
				if(dp[j]<(dp[i]+1)){
					dp[j] = dp[i]+1;
					p[j] = i;
				}
			}
		}
	}
	cout << dp[0]-1 << '\n';
	int ce = 0;
	while(p[ce]){
		if(ce) cout << ' ';
		ce = p[ce];
		cout << ce;
	}
	cout << '\n';
}

//20:28 13-08-2018
