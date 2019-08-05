//21:19 28-06-2018
//21:23 28-06-2018

#include<iostream>
#include<string>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

string g[4];

int dx1[] = {1, 1, 0, -1};
int dy1[] = {0, 1, 1, 1};
int dx2[] = {-1, -1, 0, 1};
int dy2[] = {0, -1, -1, -1};

void inc(char c, int &cx, int &cd){
	if(c=='x') cx++;
	if(c=='.') cd++;
}

bool chk(int x, int y){
	int x1, y1, x2, y2, cx, cd;
	REP(i, 0, 4){
		cx=0; cd=0;
		x1=x+dx1[i]; y1=y+dy1[i];
		x2=x+dx2[i]; y2=y+dy2[i];
		inc(g[x1][y1], cx, cd);
		inc(g[x][y], cx, cd);
		inc(g[x2][y2], cx, cd);
		if(cx==2&&cd==1) return true;
	}
	return false;
}

main(){
	REP(i, 0, 4) cin >> g[i];
	REP(i, 1, 3)
		REP(j, 1, 3)
			if(chk(i, j)){
				cout << "YES\n";
				return 0;
			}
	cout << "NO\n";
}

//21:34 28-06-2018
