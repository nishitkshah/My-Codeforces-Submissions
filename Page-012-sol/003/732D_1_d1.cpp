//20:52 16-08-2018
//20:59 16-08-2018
//21:28 16-08-2018

#include<iostream>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAX 100001

int n, m, d[MAX], a[MAX], s2d[MAX], d2s[MAX], lba[MAX];

bool chk(int p, int b){
	RE(i, 0, m+1){
		s2d[i] = -1;
	}
	RE(i, 0, p){
		s2d[d[i]] = i;
		d2s[i] = 0;
	}
	RE(i, 1, m+1){
		if(s2d[i]==-1) return (!b)^false;
		d2s[s2d[i]] = i;
	}
	long long sum = 0LL;
	RE(i, 0, p){
		if(d2s[i]){
			sum += a[d2s[i]] + 1;	//+1 for exam day
			if((i+1)<sum)
				return (!b)^false;
		}
	}
	return (!b)^true;
}

main(){
	cin >> n >> m;
	RE(i, 0, n) cin >> d[i];
	a[0] = 0;
	RE(i, 1, m+1) cin >> a[i];
	RE(i, 0, n) lba[i] = i;
	int ans = (int) (lower_bound(lba, lba+n, 1, chk)-lba);
	if(ans==n) ans = -1;
	else ans++;
	cout << ans << '\n';
}

//21:27 16-08-2018
//21:32 16-08-2018
