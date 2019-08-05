//17:25 06-12-2018 to 17:34 06-12-2018 - Before starting 540D_1.cpp
//22:38 06-12-2018
//23:01 06-12-2018
//23:03 06-12-2018

#include<iostream>
#include<cstdio>
#include<vector>
#include<tuple>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 101

int mx[3], mxs;
long double dp[N_][N_][N_];
vector< tuple<int, int, int> > lvl[3*N_];

void set_p(int a[3], long double p){
	dp[a[0]][a[1]][a[2]] = p;
}

void add_p(int a[3], long double p){
	dp[a[0]][a[1]][a[2]] += p;
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
		prob *= a[c]*a[e];
		prob /= sum;
		add_p(na, prob);
	}
}
}

main(){
RE(i, 0, 3){
	cin >> mx[i];
	mxs += mx[i];
}
RE(i, 0, mx[0]+1)
	RE(j, 0, mx[1]+1)
		RE(k, 0, mx[2]+1){
			lvl[mxs-i-j-k].push_back({i, j, k});
			dp[i][j][k] = 0.0L;
		}
set_p(mx, 1.0L);
int param[3];
RE(i, 0, mxs){
	for(auto st: lvl[i]){
		param[0] = get<0>(st);
		param[1] = get<1>(st);
		param[2] = get<2>(st);
		//cerr << param[0] << " " << param[1] << " " << param[2] << " " << get_p(param) << "\n";
		push_prob(param);
	}
}
long double ans[3] = {0.0L, 0.0L, 0.0L};
RE(i, 0, 3){
	int a[3] = {0};
	RE(v, 1, mx[i]+1){
		a[i] = v;
		//cerr << "i arr " << i << " " << a[0] << " " << a[1] << " " << a[2] << " " << get_p(a) << endl;
		ans[i] += get_p(a);
	}
}
//cerr << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
RE(i, 0 ,3){
	if(i) printf(" ");
	printf("%.12f", (double)ans[i]);
}
printf("\n");
/* //Doesn't work - MinGW GCC printf doesn't support long double - https://stackoverflow.com/questions/4089174/printf-and-long-double
RE(i, 0 ,3){
	if(i) printf(" ");
	printf("%.9le %.9le", ans[i], ans[i]);
}
printf("\n");
*/
}

//23:00 06-12-2018
//23:02 06-12-2018
//23:27 06-12-2018
