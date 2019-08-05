#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<piii> viii;

bool cmp(piii a, piii b){
	if(a.first.first>b.first.first) return false;
	else if(a.first.first==b.first.first)
		if(a.first.second<b.first.second) return false;
	return true;
}

bool cmp2(piii a, piii b){
	if(a.second>b.second) return false;
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	viii v(m), e;
	int a, b;
	REP(i, 0, m){
		cin >> a >> b;
		v.push_back({{a, b}, i});
	}
	sort(v.begin(), v.end(), cmp);
	REP(i, 0, m) cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second << "\n";
	int in1=0, out1=1, out2=2;
	bool g_valid=true;
	REP(i, 0, m){
		if(v[i].first.second==1) in1++;
		else{
			if((out1>in1)||(out2>in1)){
				cout << -1 << "\n";
				g_valid = false;
				break;
			}else{
				e.push_back({{out1, out2}, v[i].second});
				out2++;
				if(out2>in1){
					out1++;
					out2 = out1+1;
				}
			}
		}
	}
	if(g_valid){
		sort(e.begin(), e.end(), cmp2);
		REP(i, 0, m) cout << e[i].first.first << e[i].first.second << "\n";
	}
	return 0;
}
