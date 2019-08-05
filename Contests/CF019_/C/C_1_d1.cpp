//21:52 01-05-2019
//21:54 01-05-2019
//22:03 01-05-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 200010

int n, z, x[N_];
set< pair<int, int> > st, pre;

bool chk(int d){
	if(2*d>n) return false;
	st.clear();
	pre.clear();
	RE(i, 0, n) st.insert({x[i], i});
	RE(i, 0, d){
		pre.insert(*st.begin());
		st.erase(st.begin());
	}
	for(auto val: pre){
		auto it = st.lower_bound({val.first+z, 0});
		if(it!=st.end()){
			st.erase(it);
		}else{
			return false;
		}
	}
	return true;
}

int b_search(){
int l=0, h=n, m;
while(l!=(h-1)){
	m = l+(h-l)/2;
	if(chk(m)) l = m;
	else h = m;
}
return l;
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> z;
RE(i, 0, n) cin >> x[i];
cout << b_search() << '\n';
//cerr << chk(2) << '\n';
}

//22:02 01-05-2019
//22:07 01-05-2019
//22:09 01-05-2019
