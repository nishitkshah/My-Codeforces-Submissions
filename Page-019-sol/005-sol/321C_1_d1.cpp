//11:53 02-02-2019 to 12:17 02-02-2019 - Have read this problem before. Read editorial to see solutions other than Centroid Decomposition
//21:39 02-02-2019
//21:57 02-02-2019

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<c; a++)
#define N_ 100001

int n, rnk[N_], cnt[N_][26]={0}, a, b;
vector<int> t[N_];

int dfs(int nd, int pr){
int mxr = 25;
for(auto nc: t[nd])
	if(nc!=pr){
		int rc = dfs(nc, nd);
		mxr = max(mxr, rc);
		cnt[nd][rc]++;
	}
int mx = 25;
RE(i, 1, 26)
	if(cnt[nd][i]>=2){
		mx = i-1;
		break;
	}
rnk[nd] = mx;
return max(mxr, mx);
}

main(){
cin >> n;
RE(i, 1, n){
	cin >> a >> b;
	t[a].push_back(b);
	t[b].push_back(a);
}
dfs(1, 0);
RE(i, 1, n+1){
	if(i!=1) cout << ' ';
	cout << char('A'+rnk[i]);
}
cout << '\n';
}

//21:57 02-02-2019
//21:58 02-02-2019
