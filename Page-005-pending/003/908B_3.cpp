//11:57 28-06-2018

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int tdx[] = {1, 0, -1, 0};
int tdy[] = {0, 1, 0, -1};

int n, m;
vector<string> g;
string s;
int ind[] = {0, 1, 2, 3};
int dx[4], dy[4];

bool next_perm(){
	REP(i, 0, 4){
		dx[ind[i]] = tdx[i];
		dy[ind[i]] = tdy[i];
	}
	return next_permutation(ind, ind+4);
}

bool next_pos(int &cx, int &cy, char dir){
	int d = dir-'0';
	cx += dx[d];
	cy += dy[d];
	if(cx<0||cx>=n) return false;
	if(cy<0||cy>=m) return false;
	if(g[cx][cy]=='#') return false;
	return true;
}

main(){
	cin >> n >> m;
	g.resize(n);
	REP(i, 0, n) cin >> g[i];
	cin >> s;
	int sx, sy, ex, ey;
	REP(i, 0, n)
		REP(j, 0, m){
			if(g[i][j]=='S') sx = i, sy = j;
			if(g[i][j]=='E') ex = i, ey = j;
		}
	int cnt=0;
	while(true){
		bool has_next = next_perm();
		int cx=sx, cy=sy;
		REP(i, 0, s.size()){
			if(!next_pos(cx, cy, s[i])) break;
			if(cx==ex&&cy==ey){
				cnt++;
				break;
			}
		}
		if(!has_next) break;
	}
	cout << cnt << "\n";
}

//12:12 28-06-2018
//12:13 28-06-2018
