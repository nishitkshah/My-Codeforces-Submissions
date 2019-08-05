//21:28 10-04-2019 - read the problem before - writing the more difficult solution
//21:37 10-04-2019
//21:49 10-04-2019
//21:51 10-04-2019
//21:55 10-04-2019
//21:56 10-04-2019
//22:00 10-04-2019
//22:06 10-04-2019
//22:22 10-04-2019
//00:47 11-04-2019 - 1118E_2.cpp

#include<iostream>
#include<set>
#include<utility>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 200001

int n, k;
set<int> s[N_];

main(){
cin >> n >> k;
if( ((long long)n) > (((long long)k)*(k-1)) ){
	cout << "NO\n";
	return 0;
}
cout << "YES\n";
int cnt=0;
RE(i, 1, k+1){
	RE(j, 1, k+1){
		cout << j << ' ' << (i+j-1)%k+1 << '\n';
		cnt++;
		if(cnt==n) break;
	}
	if(cnt==n) break;
}
}

//21:47 10-04-2019
//21:49 10-04-2019
//21:52 10-04-2019
//21:55 10-04-2019
//21:57 10-04-2019
//22:01 10-04-2019
//22:19 10-04-2019
//22:23 10-04-2019
//00:50 11-04-2019
//00:52 11-04-2019
