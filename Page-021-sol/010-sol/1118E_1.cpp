//21:28 10-04-2019 - read the problem before - writing the more difficult solution
//21:37 10-04-2019

#include<iostream>
#include<set>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 200001

int n, k;
set<int> s[N_];

main(){
cin >> n >> k;
if( n > (k*(k-1)) ){
	cout << "NO\n";
	return 0;
}
cout << "YES\n";
RE(i, 1, k+1)
	RE(j, 1, k+1)
		if(i!=j) s[i].insert(j);
int pa=-1, pb=-1;
RE(j, 1, n+1){
	RE(a, 1, k+1){
		for(auto b: s[a]){
			if(b!=pb){
				s[a].erase(b);
				pa = a;
				pb = b;
				break;
			}
		}
		cout << pa << ' ' << pb << '\n';
	}
}
}

//21:47 10-04-2019
