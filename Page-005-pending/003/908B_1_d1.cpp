//09:22 28-06-2018
//09:31 28-06-2018
//10:00 28-06-2018

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

//string dir[] = {"Left ", "Up ", "Right ", "Down "};

bool next_perm(){
	REP(i, 0, 4){
		// cerr << dir[i] << ind[i] << " ";
		px[ind[i]] = dx[i];
		py[ind[i]] = dy[i];
	}
	// cerr << "\n";
	return next_permutation(ind, ind+4);
}

bool next_pos(int &cx, int &cy, int dx, int dy){
	cx += dx;
	cy += dy;
	// cerr << "In pos " << dx << " " << dy << "\n";
	if(cx<0||cx>=n) return false;
	if(cy<0||cy>=m) return false;
	if(g[cx][cy]=='#') return false;
	// cerr << "pos success\n";
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
	// cerr << sx << " " << sy << " " << ex << " " << ey << "\n";
	cin >> s;
	// cerr << "S: " << s << "\n";
	int cnt = 0;
	while(true){
		bool can_perm = next_perm();
		// REP(i, 0, 4) cerr << px[i] << " ";
		// cerr << "\n";
		// REP(i, 0, 4) cerr << py[i] << " ";
		// cerr << "\n";
		int cx=sx, cy=sy;
		REP(i, 0, s.size()){
			// cerr << cx << " " << cy << " " << s[i] << "\n";
			// cerr << "Dbgg: " << s[i] << " " << px[s[i]] << " " << py[s[i]] << "\n";
			if(!next_pos(cx, cy, px[s[i]-'0'], py[s[i]-'0'])){
				// cerr << cx << " " << cy << " break\n";
				break;
			}
			if(cx==ex&&cy==ey){
				cnt++;
				break;
			}
		}
		if(!can_perm) break;
	}
	cout << cnt << "\n";
}

//09:58 28-06-2018
//10:37 28-06-2018
//10:38 28-06-2018
