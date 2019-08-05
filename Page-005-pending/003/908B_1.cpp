//09:22 28-06-2018
//09:31 28-06-2018

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int n, m, sx, sy, ex, ey;
vector<string> g;
int ind[] = {0, 1, 2, 3};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int px[] = {1, 0, -1, 0};
int py[] = {0, 1, 0, -1};

bool next_perm(){
	REP(i, 0, 4){
		px[ind[i]] = dx[i];
		py[ind[i]] = dy[i];
	}
	return next_permutation(ind, ind+3);
}

bool next_pos(int &cx, int &cy, int dx, int dy){
	cx += dx;
	cy += dy;
	if(cx<0||cx>=n) return false;
	if(cy<0||cy>=m) return false;
	if(g[cx][cy]=='#') return false;
	return true;
}

main(){
	cin >> n >> m;
	g.resize(n);
	string s;
	REP(i, 0, n) cin >> g[i];
	REP(i, 0, n)
		REP(j, 0, m){
			if(g[i][j]=='S'){
				sx = i; sy = j;
			}
			if(g[i][j]=='E'){
				ex = i; ey = j;
			}
		}
	cin >> s;
	int cnt = 0;
	while(next_perm()){
		int cx=sx, cy=sy;
		REP(i, 0, s.size()){
			if(!next_pos(cx, cy, dx[s[i]], dy[s[i]])){
				break;
			}
			if(cx==ex&&cy==ey){
				cnt++;
				break;
			}
		}
	}
	cout << cnt << "\n";
}

//09:58 28-06-2018
