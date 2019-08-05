//01:04 19-07-2019 to 01:08 19-07-2019
//23:20 20-07-2019
//23:39 20-07-2019

#include<bits/stdc++.h>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100010
#define M_ 7

int n, m, k, a[N_][M_], l, r, mxl=0, ans[M_]={0};
deque< pair<int, int> > dq[M_];

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> m >> k;
RE(i, 0, n)
	RE(j, 0, m) cin >> a[i][j];
l = 0;
r = -1;
RE(i, 0, n){
	r = i;
	int cmx = 0;
	RE(j, 0, m){
		if(!dq[j].empty()){
			auto bk = dq[j].back();
			while(bk.first<a[i][j]){
				dq[j].pop_back();
				if(dq[j].empty()) break;
				bk = dq[j].back();
			}
		}
		dq[j].push_back({a[i][j], i});
		cmx += dq[j].front().first;
	}
	while(l<r && cmx>k){
		cmx = 0;
		RE(j, 0, m){
			if(dq[j].front().second==l)
				dq[j].pop_front();
			cmx += dq[j].front().first;
		}
		l++;
	}
	if(cmx<=k && mxl<(r-l+1)){
		RE(j, 0, m)
			ans[j] = dq[j].front().first;
		mxl = r-l+1;
	}
}
RE(j, 0, m){
	if(j) cout << ' ';
	cout << ans[j];
}
cout << '\n';
}

//23:39 20-07-2019
//23:44 20-07-2019
//23:45 20-07-2019
