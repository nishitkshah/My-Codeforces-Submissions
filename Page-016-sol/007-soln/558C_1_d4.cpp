//22:34 03-12-2018
//22:46 03-12-2018
//23:04 03-12-2018
//23:10 03-12-2018
//23:21 03-12-2018
//23:24 03-12-2018

#include<iostream>
#include<unordered_set>
#include<queue>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100001

int n, a[N_], sum[N_]={0}, cnt[N_]={0}, mx;
unordered_set<int> s;

void rec(int v){
int l=0;
queue< pair<int, int> > q;
q.push({v, l});
while(q.size()){
	v = q.front().first;
	l = q.front().second;
	q.pop();
	if(!s.count(v)){
		sum[v] += l;
		cnt[v] += 1;
		s.insert(v);
		int uv=v<<1, lv=v>>1;
		cerr << v << ' ' << l << ' ' << uv << ' ' << lv << endl;
		if(uv && uv<=mx){
			cerr << "uv\n";
			q.push({uv, l+1});
		}
		if(lv){
			cerr << "lv\n";
			q.push({lv, l+1});
		}
	}
}
cerr << endl;
}

main(){
cin >> n;
mx = 0;
RE(i, 0, n){
	cin >> a[i];
	if(a[i]>mx) mx = a[i];
	s.clear();
	rec(a[i]);
}
int mn = N_;
RE(i, 0, N_)
	if(cnt[i]==n && sum[i]<mn)
		mn = sum[i];
RE(i, 0, 33)
	cerr << i << ' ' << sum[i] << ' ' << cnt[i] << '\n';
cout << mn << '\n';
}

//23:02 03-12-2018
//23:05 03-12-2018
//23:15 03-12-2018
//23:21 03-12-2018
//23:40 03-12-2018
