#include<iostream>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)
#define MAX 501

int n, m, q, r1, c1, r2, c2, g[MAX][MAX], dpd[MAX][MAX], dpr[MAX][MAX];
char c;

int main(){
	ios::sync_with_stdio(0);
	cin >> n >> m;
	REP(i, 0, n)
		REP(j, 0, m){
			cin >> c;
			if(c=='.') g[i][j] = 1;
			else g[i][j] = 0;
		}
	REP(i, 0, n)
		REP(j, 0, m) dpd[i][j] = dpr[i][j] = 0;
	REP(i, 0, n-1)
		REP(j, 0, m)
			if((g[i][j])&&(g[i+1][j])) dpd[i][j]++;
	REP(i, 0, n)
		REP(j, 0, m-1)
			if((g[i][j])&&(g[i][j+1])) dpr[i][j]++;
	REP(i, 0, n)
		REP(j, 1, m){
			dpd[i][j] += dpd[i][j-1];
			dpr[i][j] += dpr[i][j-1];
		}
	REP(i, 1, n)
		REP(j, 0, m){
			dpd[i][j] += dpd[i-1][j];
			dpr[i][j] += dpr[i-1][j];
		}
	cin >> q;
	REP(i, 0, q){
		cin >> r1 >> c1 >> r2 >> c2;
		r1--; c1--; r2--; c2--;
		if((r1==r2)&&(c1==c2)) cout << 0 << "\n";
		else{
			int cnt = 0;
			if(r2) cnt += dpd[r2-1][c2];
			if(r2&&c1) cnt -= dpd[r2-1][c1-1];
			if(r1&&c1) cnt += dpd[r1-1][c1-1];
			if(r1) cnt -= dpd[r1-1][c2];
			if(c2) cnt += dpr[r2][c2-1];
			if(c1) cnt -= dpr[r2][c1-1];
			if(r1&&c1) cnt += dpr[r1-1][c1-1];
			if(r1&&c2) cnt -= dpr[r1-1][c2-1];
			cout << cnt << "\n";
		}
	}
	return 0;
}
