#include<iostream>
#include<string>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int m, n, x, y, a[100000+1000], cnt;

bool isVal(int x, int y){
	if(x<0||y<0||x>=m||y>=n) return false;
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cnt = 0;
	string s;
	cin >> m >> n >> x >> y;
	cin >> s;
	int px=-1, py=-1, cx=x-1, cy=y-1;
	REP(i, 0, s.length()-1){
		if((px!=cx)||(py!=cy)){
			a[i] = 1;
			cnt++;
		}else{
			a[i] = 0;
		}
		//Forgot to add logic for change of cell
	}
	a[s.length()-1] = m*n-cnt;
	cout << a[0];
	REP(i, 1, s.length()) cout << " " << a[i];
	return 0;
}
