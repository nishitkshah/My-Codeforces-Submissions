//18:17 01-07-2018
//18:32 01-07-2018
//18:43 01-07-2018
//18:47 01-07-2018

#include<iostream>
#include<unordered_set>

using namespace std;

int n, k, ne=1, d;
unordered_set<int> s;

main(){
	cin >> n >> k;
	if(k<(n/2) || ((n==1) && (k>0))){
		cout << "-1\n";
		return 0;
	}
	if(n==1){
		cout << "1\n";
		return 0;
	}
	d = k-(n/2);
	cout << d+1 << " " << 2*(d+1);
	s.insert(d+1);
	s.insert(2*(d+1));
	n -= 2;
	while(n>1){
		if(s.count(ne)!=0||s.count(ne+1)!=0){
			ne++;
			continue;
		}
		cout << " " << ne << " " << ne+1;
		ne += 2;
		n -= 2;
	}
	if(n) cout << " 10000000";
	cout << '\n';
}

//18:42 01-07-2018
//18:43 01-07-2018
//18:49 01-07-2018
//18:50 01-07-2018
