//22:34 03-12-2018
//22:46 03-12-2018
//23:04 03-12-2018
//23:10 03-12-2018
//23:21 03-12-2018
//23:24 03-12-2018
//23:41 03-12-2018
//23:47 03-12-2018

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
		if(uv && uv<=mx)
			q.push({uv, l+1});
		if(lv)
			q.push({lv, l+1});
	}
}
}

main(){
cin >> n;
mx = 0;
RE(i, 0, n){
	cin >> a[i];
	if(a[i]>mx) mx = a[i];
}
RE(i, 0, n){
	s.clear();
	rec(a[i]);
}
int mn = 1000*N_;
RE(i, 0, N_)
	if(cnt[i]==n && sum[i]<mn)
		mn = sum[i];
cout << mn << '\n';
}

//23:02 03-12-2018
//23:05 03-12-2018
//23:15 03-12-2018
//23:21 03-12-2018
//23:40 03-12-2018
//23:42 03-12-2018
//00:11 04-12-2018
//00:11 04-12-2018
