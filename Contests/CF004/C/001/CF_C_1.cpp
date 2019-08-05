#include<iostream>
#include<vector>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

typedef vector< vector<char> > vvc;

char rev(char c){
	if(c=='+') return '*';
	return '+';
}

vvc nxt(vvc v){
	vvc ret=v, rv=v;
	REP(i, 0, v.size()) ret.push_back(v[i]);
	REP(i, 0, rv.size())
		REP(j, 0, rv[i].size())
			rv[i][j] = rev(rv[i][j]);
	REP(i, 0, v.size())
		REP(j, 0, v[i].size())
			ret[i].push_back(v[i][j]);
	REP(i, 0, rv.size())
		REP(j, 0, rv.size())
			ret[v.size()+i].push_back(rv[i][j]);
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	vvc v = {{'+'}};
	int n;
	cin >> n;
	REP(i, 0, n) v = nxt(v);
	REP(i, 0, v.size()){
		REP(j, 0, v[i].size()) cout << v[i][j];
		if(i!=(v.size()-1)) cout << "\n";
	}
	return 0;
}
