//21:45 17-03-2019 - read Editorial
//22:01 17-03-2019

#include<iostream>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100000

int n, c[N_], t[N_], dc[N_], dt[N_];

main(){
cin >> n;
RE(i, 0, n) cin >> c[i];
RE(i, 0, n) cin >> t[i];
RE(i, 0, n-1){
	dc[i] = c[i]-c[i+1];
	dt[i] = t[i]-t[i+1];
}
sort(dc, dc+n-1);
sort(dt, dt+n-1);
bool same = true;
RE(i, 0, n-1)
	if(dc[i]!=dt[i]) same = false;
if(c[0]!=t[0]) same = false;
if(same) cout << "Yes\n";
else  cout << "No\n";
}

//22:05 17-03-2019
//22:07 17-03-2019
