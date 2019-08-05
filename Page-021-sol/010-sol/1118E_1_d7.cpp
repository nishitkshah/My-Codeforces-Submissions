//21:28 10-04-2019 - read the problem before - writing the more difficult solution
//21:37 10-04-2019
//21:49 10-04-2019
//21:51 10-04-2019
//21:55 10-04-2019
//21:56 10-04-2019
//22:00 10-04-2019
//22:06 10-04-2019
//22:22 10-04-2019

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
int d = (n+k-1)/k + 5;
d = min(k, d);
RE(i, 1, k+1)
	RE(j, 1, d+1)
		if(i!=j) s[i].insert(j);
int pa=-1, pb=-1, cnt=0;
//RE(i, 1, k+1){
//	for(auto v: s[i])
//		cerr << v << ' ';
//	cerr << '\n';
//}
while(cnt<n){
	RE(a, 1, k+1){
		if(a%2){
			for(auto b: s[a]){
				//cerr << "Testing " << b << " in " << a << '\n';
				if(b!=pb){
					s[a].erase(b);
					//cerr << "Erased " << b << " in " << a << '\n';
					pa = a;
					pb = b;
					break;
				}
			}
		}else{
			for(auto it=s[a].rbegin(); it!=s[a].rend(); it++){
				int b = *it;
				if(b!=pb){
					s[a].erase(b);
					pa = a;
					pb = b;
					break;
				}
			}
		}
		cout << pa << ' ' << pb << '\n';
		cnt++;
		if(cnt>=n) break;
	}
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
//22:25 10-04-2019
