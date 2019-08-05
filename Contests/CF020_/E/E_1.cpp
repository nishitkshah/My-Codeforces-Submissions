//00:23 05-05-2019
//00:25 05-05-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

int n, a[70];

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n;
RE(i, 0, n) cin >> a[i];
RE(i, 1, n) a[0] ^= a[i];
if(a[0]) cout << "Alice\n";
else cout << "Bob\n";
}

//00:26 05-05-2019
//00:27 05-05-2019
