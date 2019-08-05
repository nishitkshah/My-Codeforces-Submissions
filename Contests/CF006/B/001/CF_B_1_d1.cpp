#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

typedef pair<int, string> pis;

int n, m, r, scr;
string s;
vector< vector<pis> > v[10010];

bool cmp(pis a, pis b){
	if(a.first<b.first) return true;
	return false;
}

int main(){
	//ios::sync_with_stdio(0);
	cin >> n >> m;
	REP(i, 0, n){
		cin >> s >> r >> scr;
		pis tmp = {scr, s};
		(v[r]).push_back(tmp);
	}
	REP(i, 1, m+1)
		sort(v[i].begin(), v[i].end(), cmp);
	REP(i, 1, m+1){
		if(v[i].size()==2)
			cout << v[i][0].second << " " << v[i][1].second << "\n";
		else{
			if(v[i][1].first==v[i][2].first) cout << "?\n";
			else cout << v[i][0].second << " " << v[i][1].first << "\n";
		}
	}
	return 0;
}
