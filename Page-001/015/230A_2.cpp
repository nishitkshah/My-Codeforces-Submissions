//17:55 16-05-2018

#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int s, n, x, y;
vector< pair<int, int> > v;

int main(){
	cin >> s >> n;
	REP(i, 0, n){
		cin >> x >> y;
		v.push_back({x, y});
	}
	sort(v.begin(), v.end());
	REP(i, 0, n){
		if(s<=v[i].first){
			cout << "NO\n";
			return 0;
		}
		s += v[i].second;
	}
	cout << "YES\n";
	return 0;
}

//18:02 16-05-2018
//18:05 16-05-2018
