//21:42 21-07-2019 to 22:28 21-07-2019
//22:44 21-07-2019

#include<bits/stdc++.h>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 30

int n, a[N_];
set<int> b;

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n;
RE(i, 0, n){
	cin >> a[i];
	b.insert(a[i]);
}
RE(i, 0, n){
	if(i) cout << ' ';
	if(*(b.begin())==a[i]){
		cout << *(b.rbegin());
	}else{
		cout << *(b.find(a[i])--);
	}
}
cout << '\n';
}

//22:50 21-07-2019
