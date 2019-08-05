#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<utility>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int n, k, a, b;
vector< pair<int, int> > s, m;
vector<int> l;
set<int> st;
map<int, int> mp;

int main(){
	ios::sync_with_stdio(0);
	cin >> n >> k;
	REP(i, 0, n){
		cin >> a >> b;
		s.push_back({a, b});
		st.insert(a);
		st.insert(b);
	}
	int ind=0;
	for(set<int>::iterator it=st.begin(); it!=st.end(); it++){
		l.push_back(*it);
		mp[*it] = ind++;
	}
	REP(i, 0, n) m.push_back({mp[s[i].first], mp[s[i].second]});
	sort(m.begin(), m.end());
	REP(i, 0, n){
		cout << m[i].first << " " << m[i].second << endl;
	}
	return 0;
}
