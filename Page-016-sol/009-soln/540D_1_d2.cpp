//17:25 06-12-2018 to 17:34 06-12-2018
//17:39 06-12-2018
//18:18 06-12-2018
//18:21 06-12-2018

#include<iostream>
#include<vector>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 101
#define L_ 1000001

struct state{
int r, s, p;
};

int mx[3], mxs=0;
long double dp[N_][N_][N_] = {0.0L};
vector<state> lvl[L_];

int sums(int a[3]){
return a[0]*a[1]+a[1]*a[2]+a[2]*a[0];
}

long double prob(int a[3]){
	cerr << "Prob: " << a[0] << ' ' << a[1] << ' ' << a[2] << ' ' << dp[a[0]][a[1]][a[2]] << '\n';
	return dp[a[0]][a[1]][a[2]];
}

void calc(int rc, int sc, int pc){
int ar[3]={rc, sc, pc};
int par[3]={rc, sc, pc};
dp[rc][sc][pc] = 0.0L;
RE(c, 0, 3){
	int e = (c+1)%3;
	par[c]++;
	int parsum = sums(par);
	if((ar[c]+1)>mx[c] || !parsum) continue;
	dp[rc][sc][pc] += prob(par)*par[c]*par[e]/parsum;
	par[c]--;
}
}

main(){
RE(i, 0, 3){
	cin >> mx[i];
	mxs += mx[i];
}
dp[mx[0]][mx[1]][mx[2]] = 1.0L;
RE(i, 0, mx[0]+1)
	RE(j, 0, mx[1]+1)
		RE(k, 0, mx[2]+1){
			state st;
			st.r=i, st.s=j, st.p=k;
			lvl[mxs-i-j-k].push_back(st);
		}
RE(l, 1, mxs){
	for(state st: lvl[l]){
		calc(st.r, st.s, st.p);
	}
}
long double ans[3] = {0.0L, 0.0L, 0.0L};
RE(i, 0, 3){
	int arr[3]={0, 0, 0};
	RE(ind, 1, mx[i]+1){
		arr[i] = ind;
		ans[i] += prob(arr);
	}
	if(i) cout << ' ';
	cout << ans[i];
}
cout << '\n';
cerr << '\n';
RE(i, 0, mx[0]+1){
	RE(j, 0, mx[1]+1){
		RE(k, 0, mx[2]+1){
			cerr << dp[i][j][k] << ' ';
		}
		cerr << '\n';
	}
	cerr << "\n\n";
}
}

//18:17 06-12-2018
//18:19 06-12-2018
//18:45 06-12-2018
