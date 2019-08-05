//22:38 04-05-2019
//22:41 04-05-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

int n, h, m, l, r, x, ht[70];

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> h >> m;
RE(i, 0, 70) ht[i] = h;
RE(i, 0, m){
	cin >> l >> r >> x;
	RE(j, l, r+1) ht[j] = min(ht[j], x);
}
long long ans = 0;
RE(i, 1, n) ans += ht[i]*ht[i];
cout << ans << '\n';
}

//22:45 04-05-2019
