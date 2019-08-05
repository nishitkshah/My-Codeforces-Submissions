//23:34 04-05-2019
//23:48 05-05-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 200010
#define MX 2000010
int n, m, a, b;
set<int> st[N_];
vector< pair<int, int> > v, vd;
int f[MX]={0};

void kmp_fail(){	//Used template
int m = vd.size();
f[0] = -1;
f[1] = 0;
RE(i, 2, m+1){
	int pref = f[i-1];
	while(pref>=0){
		if(vd[pref]==vd[i-1])
			break;
		else
			pref = f[pref];
	}
	f[i] = pref+1;
}
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> m;
RE(i, 0, n) st[i].push_back(0);
RE(i, 0, m){
	cin >> a >> b;
	a--; b--;
	int d = a-b;
	if(d<0) d += n;
	d = min(d, n-d);
	if( ((a+d)%n) == b ){
		st[a].push_back(d);
		st[b].push_back(-d);
	}else{
		st[b].push_back(d);
		st[a].push_back(-d);
	}
}
RE(i, 0, n){
	int first = 1;
	for(auto d: st[i]){
		v.push_back({d, first});
		first = 0;
	}
}
for(auto val: v) vd.push_back(val);
for(auto val: v) vd.push_back(val);
int l = vd.size(), lh = v.size();
bool symmetric = false;
RE(i, 0, l-1){
	if(vd[i].second && f[i]==lh){
		symmetric = true;
	}
}
if(symmetric) cout << "Yes\n";
else cout << "No\n";
}

//00:09 05-05-2019
