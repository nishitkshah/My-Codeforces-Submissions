//22:14 16-02-2019
//22:23 16-02-2019
//22:38 16-02-2019
//22:55 16-02-2019
//23:04 16-02-2019 - 1113B_2.cpp
//23:13 16-02-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 50000

int n, a[N_], ans=0;
vector<int> p[101], pr;
set< pair<int, int> > st;

inline void init(){
RE(i, 1, 101)
	RE(j, 2, i+1)
		while(i%j==0){
			p[i].push_back(j);
			i /= j;
		}
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
init();
cin >> n;
RE(i, 0, n){
	cin >> a[i];
	st.insert({1, i});
	RE(j, 0, p[a[i]].size())
		pr.push_back(p[a[i]][j]);
}
sort(pr.begin(), pr.end());
for(auto it=pr.rbegin(); it!=pr.rend(); it++){
	int v = *it;
	pair<int, int> pp, pc;
	pp = *st.begin();
	pc = pp;
	pc.first *= v;
	st.erase(pp);
	st.insert(pc);
}
for(auto pc: st)
	ans += pc.first;
cout << ans << '\n';
}

//22:37 16-02-2019
//22:39 16-02-2019
//22:56 16-02-2019 - Couldn't find any bug
//23:12 16-02-2019
//23:13 16-02-2019
