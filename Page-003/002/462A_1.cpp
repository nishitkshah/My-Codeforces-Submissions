//09:29 31-05-2018
//09:30 31-05-2018

#include<iostream>
#include<string>
#include<vector>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int n,
dx[] = {1, 0, -1, 0},
dy[] = {0, 1, 0, -1};

bool chk(int x, int y){
	if(x<0||x>=n) return false;
	if(y<0||y>=n) return false;
	return true;
}

main(){
	int n;
	cin >> n;
	vector<string> v(n);
	REP(i, 0, n) cin >> v[i];
	REP(i, 0, n){
		REP(j, 0, n){
			int cnt=0;
			REP(k, 0, 4){
				int cx=i+dx[k], cy=j+dy[k];
				if(chk(cx, cy)){
					if(v[cx][cy]=='o') cnt++;
				}
			}
			if(cnt%2){
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
}

//09:39 31-05-2018
