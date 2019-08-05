//09:41 02-06-2019 to 09:57 02-06-2019
//15:33 02-06-2019
//15:58 02-06-2019

#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 1500

int n, a[N_], mc, mx=-1;
unordered_map< int, vector< pair<int, int> > > mp;
vector< pair<int, int> > ans;

int getseq(const vector< pair<int, int> >& v, bool store=false){
int r=-1, cnt=0;
for(auto pii: v)
	if(pii.first>r){
		r = pii.second;
		cnt++;
		if(store) ans.push_back(pii);
	}
return cnt;
}

main(){
cin >> n;
RE(i, 0, n) cin >> a[i];
RE(r, 0, n){
	int sm = 0;
	for(int l=r; l>=0; l--){
		sm += a[l];
		if(!mp.count(sm))
			mp[sm] = vector< pair<int, int> >();
		mp[sm].push_back({l, r});
	}
}
for(auto cl: mp){
	int sz = getseq(cl.second);
	if(sz>mx){
		sz = mx;
		mc = cl.first;
	}
}
getseq(mp[mc], true);
cout << ans.size() << '\n';
for(auto pii: ans)
	cout << pii.first << ' ' << pii.second << '\n';
}

//15:57 02-06-2019
//15:59 02-06-2019
