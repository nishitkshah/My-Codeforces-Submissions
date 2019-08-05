//15:06 14-08-2018
//15:19 14-08-2018
//15:56 14-08-2018

#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAX 200001

int n, m, k, x, s;
pair<int, int> f[MAX], se[MAX];
long long time, mn;

main(){
	cin >> n >> m >> k >> x >> s;
	m++; k++;
	f[0] = {0, x};
	se[0] = {0, 0};
	RE(i, 1, m) cin >> f[i].second;
	RE(i, 1, m) cin >> f[i].first;
	RE(i, 1, k) cin >> se[i].second;
	RE(i, 1, k) cin >> se[i].first;
	mn = n*((long long)(x));
	RE(i, 0, m){
		int cs = f[i].first;
		pair<int, int> cap = {s-cs+1, 0};
		pair<int, int>* pt = lower_bound(se, se+k, cap);
		int j = pt-se;
		if(j==0) continue;
		j--;
		int potr = max(n-(se[j].second)-1, 0);
		time = f[i].second + potr*((long long)(x));
		mn = min(time, mn);
	}
	cout << mn << '\n';
}

//15:54 14-08-2018
//15:59 14-08-2018
