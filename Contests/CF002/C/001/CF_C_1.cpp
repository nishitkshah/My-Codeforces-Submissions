#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

vector< pair<int, int> > v;
vector<int> l, dp;
int n, a, b;

int b_search(int s){
	int x=0, y=v.size()-1;
	if(v[x].first>=s) return x;
	while(true){
		if(x==(y-1)) return y;
		int m = x+((y-x)/2);
		if(v[m].first<s) x = m;
		else y = m;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin >> n;
	v.clear();
	REP(i, 0, n){
		cin >> a >> b;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end());
	l.clear();
	l.resize(v.size());
	for(int i=n-1; i>=0; i--){
		l[i] = b_search(max(0, v[i].first-v[i].second))-1;
	}
	dp.clear();
	dp.resize(v.size());
	dp[0] = 0;
	REP(i, 1, n){
		dp[i] = 1+dp[l[i]];
	}
	int mx=0;
	REP(i, 0, n){
		mx = max(mx, dp[i]);
	}
	cout << n-mx;
	return 0;
}
