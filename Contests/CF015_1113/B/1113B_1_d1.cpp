//22:14 16-02-2019
//22:23 16-02-2019
//22:38 16-02-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 50000

int n, a[N_], ans=0;
vector<int> d[101];
set< pair<int, int> > st;

inline void init(){
RE(i, 1, 101)
	for(int j=i; j>0; j--)
		if(i%j==0)
			d[i].push_back(j);
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
init();
cin >> n;
RE(i, 0, n) cin >> a[i];
RE(i, 0, n) st.insert({a[i], i});
while(st.size()>1){
	int e = (*st.rbegin()).first;
	int ie = (*st.rbegin()).second;
	int b = (*st.begin()).first;
	int ib = (*st.begin()).second;
	for(auto v: d[e]){
		int ne=e/v, nb=b*v;
		if((nb+ne)<(b+e)){
			st.erase(*(st.rbegin()));
			st.erase(st.begin());
			st.insert({nb, ib});
			st.insert({ne, ie});
			break;
		}else
			if(v==1){
				ans += e;
				st.erase(*(st.rbegin()));
			}
	}
}
ans += (*st.begin()).first;
cout << ans << '\n';
}

//22:37 16-02-2019
//22:39 16-02-2019
//22:39 16-02-2019
