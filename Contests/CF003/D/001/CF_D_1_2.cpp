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
vector<int> l, cnt;
set<int> st;
map<int, int> mp;

vector< vector<int> > sgt, stb, ste;

void push(int v, int ind){
	int k = sgt.size()-1;
	sgt[k][ind] = v;
	for(int i=k-1; i>=0; i--){
		ind /= 2;
		sgt[i][ind] = max(v, sgt[i][ind]);
	}
}

int g_max(int s, int e){
	//ToDo
}

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
	/*
	REP(i, 0, n){
		cout << m[i].first << " " << m[i].second << endl;
	}
	*/
	//Init sum list
	cnt.resize(l.size(), 0);
	REP(i, 0, n){
		cnt[m[i].first]++;
		if((m[i].second)<(l.size()-1)) cnt[m[i].second+1]--;
	}
	REP(i, 1, l.size()) cnt[i] += cnt[i-1];
	//Begin: Init Segment Tree
	int sz = l.size();
	int k = 1;
	while(sz>1){
		k++;
		sz = (sz+1)/2;
	}
	sgt.resize(k);
	stb.resize(k);
	ste.resize(k);
	sz = l.size();
	for(int i=k-1; i>=0; i--){
		sgt[i].resize(sz, 0);
		stb[i].resize(sz, 0);
		ste[i].resize(sz, 0);
		sz = (sz+1)/2;
	}
	sz = l.size();
	REP(i, 0, sz) stb[k-1][i] = ste[i] = i;
	for(int i=k-2; i>=0; i--){
		REP(j, 0, sgt[i].size()){
			stb[i][j] = stb[i+1][2*j];
			ste[i][j] = ste[i+1][min(2*j+1, ste[i+1].size()-1)];
		}
	}
	//ToDo:
	return 0;
}
