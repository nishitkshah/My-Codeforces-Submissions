//22:05 16-02-2019
//22:10 16-02-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

int n, v;

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> v;
n--; v--;
int ans;
if(v>=n)
	ans = n;
else
	ans = v + ((n-v)*(n-v+1)/2);
cout << ans << '\n';
}

//22:12 16-02-2019
//22:13 16-02-2019
