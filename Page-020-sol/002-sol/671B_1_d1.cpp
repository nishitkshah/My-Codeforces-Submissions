//12:54 10-02-2019
//13:07 10-02-2019
//13:32 10-02-2019

#include<iostream>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 500000
#define MX 1000000001

int n, k, c[N_];
long long sm=0LL;

int bs_mx(){
int l=0, h=MX, m;
long long sm=0LL;
while(l!=(h-1)){
	m = l+(h-l)/2;
	sm = 0LL;
	for(int i=n-1; i>=0; i--){
		if(c[i]<=m) break;
		sm += c[i]-m;
		if(sm>k) break;
	}
	if(sm<=k) h = m;
	else l = m;
}
return h;
}

int bs_mn(){
int l=0, h=MX, m;
long long sm=0LL;
while(l!=(h-1)){
	m = l+(h-l)/2;
	sm = 0LL;
	RE(i, 0, n){
		if(c[i]>=m) break;
		sm += m-c[i];
		if(sm>k) break;
	}
	if(sm<=k) l = m;
	else h = m;
}
return l;
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> k;
RE(i, 0, n){
	cin >> c[i];
	sm += c[i];
}
sort(c, c+n);
if(sm<=k){
	cout << (sm%n ? 1 : 0) << '\n';
	return 0;
}
int mx=bs_mx(), mn=bs_mn();
//cerr << mx << ' ' << mn << '\n';
if(mx>=mn) cout << mx-mn << '\n';
else cout << (sm%n ? 1 : 0) << '\n';
}

//13:29 10-02-2019
//13:34 10-02-2019
//13:37 10-02-2019
