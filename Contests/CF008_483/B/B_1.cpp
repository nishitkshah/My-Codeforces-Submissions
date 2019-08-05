//20:21 15-05-2018
//20:24 15-05-2018

#include<iostream>
#include<vector>
#include<string>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int n, m;
vector<string> v;
bool chk=true;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

bool isVal(int x, int y){
	if((x<0)||(y<0)||(x>=n)||(y>=m)) return false;
	return true;
}

void chkCell(int x, int y){
	if(v[x][y]=='.'){
		REP(i, 0, 8){
			int cx = x+dx[i];
			int cy = y+dy[i];
			if(isVal(cx, cy)){
				if(v[cx][cy]=='*') chk = false;
			}
		}
	}
	if((v[x][y]!='.')&&(v[x][y]!='*')){
		int dig = v[x][y]-'0', cnt=0;
		REP(i, 0, 8){
			int cx = x+dx[i];
			int cy = y+dy[i];
			if(isVal(cx, cy)){
				if(v[cx][cy]=='*') cnt++;
			}
		}
		if(dig!=cnt) chk = false;
	}
}

int main(){
	cin >> n >> m;
	v.resize(n);
	REP(i, 0, n) cin >> v[i];
	REP(i, 0, n){
		REP(j, 0, m){
			chkCell(i, j);
		}
	}
	if(chk) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}

//20:36 15-05-2018
//20:38 15-05-2018
