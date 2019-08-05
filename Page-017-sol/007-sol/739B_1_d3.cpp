//23:27 24-12-2018 to 23:44 24-12-2018 - read editorial
//15:00 26-12-2018
//15:32 26-12-2018
//15:34 26-12-2018
//16:00 26-12-2018 - Referred to 'https://codeforces.com/contest/739/submission/35115122' and 'https://codeforces.com/contest/739/submission/35115122'

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define SI(a) scanf("%d", &(a))
#define N_ 200000

int n, a[N_], stki[N_], sm[N_]={0};
long long stk[N_];
vector<int> v[N_], w[N_];

int dfs(int nd, int l=0, long long d=0LL){
stk[l] = d;
stki[l] = nd;
long long mn = d-a[nd];
int pt = lower_bound(stk, stk+l+1, mn) - stk;
if(pt) sm[stki[pt-1]]--;
if(l) sm[stki[l-1]]++;
RE(i, 0, v[nd].size())
	sm[nd] += dfs(v[nd][i], l+1, d+w[nd][i]);
return sm[nd];
}

main(){
SI(n);
RE(i, 0, n) SI(a[i]);
RE(i, 1, n){
	int pi, wi;
	SI(pi); SI(wi);
	pi--;
	v[pi].push_back(i);
	w[pi].push_back(wi);
}
dfs(0);
RE(i, 0, n){
	if(i) printf(" ");
	printf("%d", sm[i]);
}
printf("\n");
}

//15:30 26-12-2018
//15:33 26-12-2018
//15:35 26-12-2018
//16:13 26-12-2018
//16:17 26-12-2018
