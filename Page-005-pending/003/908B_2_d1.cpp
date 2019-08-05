//10:39 28-06-2018
//10:59 28-06-2018

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int n, m;
vector<string> g;
string s;

int ind[] = {0, 1, 2, 3};
int tdx[] = {1, 0, -1, 0};
int tdy[] = {0, 1, 0, -1};
int dx[4], dy[4];

void init(){
	REP(i, 0, 4) dx[ind[i]] = tdx[i], dy[ind[i]] = tdy[i];
}

bool next_perm(){
	bool ret = next_permutation(ind, ind+4);
	init();
	return ret;
}

bool next_pos(int &cx, int &cy, int dir){
	cx += dx[dir];
	cy += dy[dir];
	// cerr << "Dbg: " << cx << " " << cy << "\n";
	if(cx<0||cx>=n) return false;
	if(cy<0||cy>=m) return false;
	// cerr << g[cx][cy] << endl;
	if(g[cx][cy]=='#') return false;
	return true;
}

main(){
	init();
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
	// cerr << "Coor: " << sx << " " << sy << " " << ex << " " << ey << " " << g[4][3] << "\n";
	int cnt=0;
	do{
		// REP(i, 0, 4) cerr << ind[i] << " ";
		// cerr << endl;
		int cx=sx, cy=sy;
		// cerr << "Dbg: " << cx << " " << cy << endl;
		REP(i, 0, s.size()){
			// cerr << endl;
			if(!next_pos(cx, cy, s[i]-'0')) break;
			// cerr << "Dbg: " << cx << " " << cy << endl;
			if(cx==ex&&cy==ey){
				cnt++;
				break;
			}
		}
		// cerr << "====\n";
	}while(next_perm());
	cout << cnt << "\n";
}

//10:58 28-06-2018
//11:54 28-06-2018
