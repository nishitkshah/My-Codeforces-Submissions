//15:06 14-08-2018
//15:19 14-08-2018

#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAX 200001

int n, m, k, x, s;
pair<int, int> f[MAX], s[MAX]
long long time, mn;

main(){
	cin >> n >> m >> k >> x >> s;
	f[0] = {0, x};
	s[0] = {0, 0};
	RE(i, 0, m) cin >> f[i].second;
	RE(i, 0, m) cin >> f[i].first;
	RE(i, 0, k) cin >> s[i].second;
	RE(i, 0, k) cin >> s[i].first;
	mn = n*((long long)(x));
	RE(i, 0, m){
		int cs = f[i].first;
		pair<int, int>* pt = lower_bound(s, s+k, {s-cs+1, 0});
		int j = pt-s;
		if(j==0) continue;
		j--;
		int potr = max(n-(s[j].second)-1, 0);
		time = f[i].second + potr*((long long)(x));
		mn = min(time, mn);
	}
	cout << mn << '\n';
}

//15:54 14-08-2018
