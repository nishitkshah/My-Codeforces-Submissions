//12:11 16-08-2018
//12:19 16-08-2018
//12:39 16-08-2018

#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAX 200000
#define MAXD 2000000000

int n, m, a[MAX], b[MAX];

pair<int, int> get_score(int d){
	int ad = lower_bound(a, a+n, d+1)-a;
	int bd = lower_bound(b, b+m, d+1)-b;
	return {2*(n) + (n-ad), 2*(m) + (m-bd)};
}

main(){
	cin >> n;
	RE(i, 0, n) cin >> a[i];
	cin >> m;
	RE(i, 0, m) cin >> b[i];
	sort(a, a+n);
	sort(b, b+m);
	long long mx=-3LL*MAXD;
	pair<int, int> mxp, p;
	RE(i, 0, n){
		p = get_score(a[i]-1);
		if((p.first-p.second) > mx){
			mxp = p;
			mx = (p.first-p.second);
		}
	}
	p = get_score(a[n-1]);
	if((p.first-p.second) > mx){
		mxp = p;
		mx = (p.first-p.second);
	}
	p = get_score(b[m-1]);
	if((p.first-p.second) > mx){
		mxp = p;
		mx = (p.first-p.second);
	}
	cout << mxp.first << ':' << mxp.second << '\n';
}

//12:36 16-08-2018
//12:42 16-08-2018
//12:43 16-08-2018
