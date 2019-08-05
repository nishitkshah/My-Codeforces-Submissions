//19:35 13-04-2019
//19:39 13-04-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 1000000

int n, t, tmn=N_, ti=-1;

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> t;
RE(i, 0, n){
	int si, di, ki=0;
	cin >> si >> di;
	if(si<t)
		ki = (t-si+di-1)/di;
	si = si+di*ki;
	if(tmn>si){
		tmn = si;
		ti = i+1;
	}
}
cout << ti << '\n';
}

//19:44 13-04-2019
//19:45 13-04-2019
