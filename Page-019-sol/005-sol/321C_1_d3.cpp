//11:53 02-02-2019 to 12:17 02-02-2019 - Have read this problem before. Read editorial to see solutions other than Centroid Decomposition
//21:39 02-02-2019
//21:57 02-02-2019
//22:11 02-02-2019
//22:31 02-02-2019

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<c; a++)
#define N_ 100001

int n, rnk[N_], cnt[N_][26]={0}, a, b;
vector<int> t[N_];

void dfs(int nd, int pr){
for(auto nc: t[nd])
	if(nc!=pr){
		dfs(nc, nd);
		RE(i, 0, 26)
			cnt[nd][i] += cnt[nc][i];
	}
bool cnt2 = false;
int ndr=25, mxe=0, mn2=25;
RE(i, 0, 26){
	if(cnt[nd][i]>=2){
		cnt2 = true;
		mn2 = min(mn2, i);
	}
	if(cnt[nd][i]==0)
		mxe = i;
}
if(cnt2){
	ndr = mn2-1;
	while(cnt[nd][ndr]) ndr--;
}else{
	ndr = mxe;
}
cnt[nd][ndr]++;
RE(i, ndr+1, 26)
	cnt[nd][i] = 0;
rnk[nd] = ndr;
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
//22:30 02-02-2019
//22:32 02-02-2019
//22:35 02-02-2019
