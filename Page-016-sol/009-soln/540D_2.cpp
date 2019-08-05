//17:25 06-12-2018 to 17:34 06-12-2018 - Before starting 540D_1.cpp
//22:38 06-12-2018

#include<iostream>
#include<vector>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 101

int mx[3], mxs;
long double dp[N_][N_][N_];
vector< tuple<int, int, int> > lvl[3*N_];

void set_p(int a[3], long double p){
	dp[a[0]][a[1]][a[2]] = p;
}

long double get_p(int a[3]){
	return dp[a[0]][a[1]][a[2]];
}

void push_prob(int a[3]){
int sum = 0;
RE(i, 0, 3) sum += a[i]*a[(i+1)%3];
RE(c, 0, 3){
	int e = (c+1)%3;
	if(a[e] && a[c]){
		int na[3] = {a[0], a[1], a[2]};
		na[c]--;
		long double prob = get_p(a);
		prob *= na[c]*na[e];
		prob /= sum;
		set_p(na, prob);
	}
}
}

main(){
RE(i, 0, 3){
	cin >> mx[i];
	mxs += mx[i];
}
set_p(mx, 1.0L);
RE(i, 0, mx[0]+1)
	RE(j, 0, mx[1]+1)
		RE(k, 0, mx[2]+1){
			lvl[mxs-i-j-k].push_back({i, j, k});
			dp[i][j][k] = 0.0L;
		}
int param[3];
RE(i, 0, mxs){
	for(auto st: lvl[i]){
		param[0] = get<0>(st);
		param[1] = get<1>(st);
		param[2] = get<2>(st);
		push_prob(param);
	}
}
long double ans[3] = {0.0L, 0.0L, 0.0L};
RE(i, 0, 3){
	int a[3] = {0};
	RE(v, 1, mx[i]+1){
		a[i] = v;
		ans[i] += get_p(a);
	}
	if(i) printf(" ");
	printf("%Lf", ans[i]);
}
printf("\n");
}

//23:00 06-12-2018
