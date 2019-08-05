//17:39 03-07-2018 to 17:45 03-07-2018
//18:04 03-07-2018

#include<iostream>
#include<unordered_set>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

main(){
	int n, m;
	bool cancel = false;
	cin >> n >> m;
	RE(i, 0, m){
		int k, t;
		cin >> k;
		unordered_set<int> s;
		bool risky = true;
		RE(j, 0, k){
			cin >> t;
			if(s.count(-t)) risky = false;
			s.insert(t);
		}
		if(risky) cancel = true;
	}
	cout << (cancel ? "YES" : "NO") << '\n';
}

//18:10 03-07-2018
//18:13 03-07-2018
