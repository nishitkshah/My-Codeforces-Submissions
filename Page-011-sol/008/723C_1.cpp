//14:24 14-08-2018
//14:39 14-08-2018

#include<iostream>
#include<set>
#include<vector>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

int n, m, mn, a[2000];
set< pair<int, int> > s;
vector<int> epos;
vector< vector<int> > v;

main(){
	cin >> n >> m;
	mn = n/m;
	v.resize(m+1);
	RE(i, 0, n){
		cin >> a[i];
		if(a[i]<=m){
			v[a[i]].push_back(i);
		}else{
			epos.push_back(i);
		}
	}
	RE(i, 1, m+1){
		s.insert({v[i].size(), i});
		RE(j, mn, v[i].size()){
			epos.push_back(v[i][j]);
		}
	}
	int pt=0;
	for(auto p: s){
		if(p.first>=mn)
			break;
		RE(i, p.first, mn){
			a[epos[pt++]] = p.second;
		}
	}
	cout << mn << ' ' << pt << '\n';
	RE(i, 0, n){
		if(i) cout << ' ';
		cout << a[i];
	}
	cout << '\n';
}

//14:57 14-08-2018
//14:59 14-08-2018
