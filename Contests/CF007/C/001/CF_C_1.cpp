#include<iostream>
#include<set>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int n, m, a, c, t[1000000], ind=0;
set<int> s

int main(){
	cin >> n >> m;
	REP(i, 0, n){
		cin >> a;
		s.insert(a);
	}
	c=0;
	REP(i, 0, 1000001){
		if(!s.count(i)){
			c += i;
			t[ind++] = i;
		}
	}
	cout << ind << "\n";
	REP(i, 0, ind) cout << t[i] << " ";
	cout << "\n";
	return 0;
}
