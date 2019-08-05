#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int n, a, b, c, p1, p2;
vector<int> m(3), v;

int main(){
	ios::sync_with_stdio(0);
	cin >> n >> m[0] >> m[1] >> m[2];
	v.resize(n);
	REP(i, 0, n) cin >> v[i];
	sort(m.begin(), m.end());
	sort(v.begin(), v.end());
	a = m[0];
	b = m[1];
	c = m[2];
	p1 = -1; p2 = n;
	int cnt=0;
	if(v[p2-1]>(a+b+c)){
		cout << -1;
		return 0;
	}
	while(v[p2-1]>(b+c)){
		if(p1>=(p2-1)) break;
		p2--;
		cnt++; cout << "Db: " << p2 << endl;
	}
	while(v[p2-1]>(a+c)){
		if(p1>=(p2-1)) break;
		p2--;
		cnt++; cout << "Db: " << p2 << endl;
		if(p1>=(p2-1)) break;
		if(v[p1+1]<=a){
			p1++;
			cout << "Db1: " << p1 << endl;
		}
	}
	while(v[p2-1]>(a+b)){
		if(p1>=(p2-1)) break;
		p2--;
		cnt++; cout << "Db: " << p2 << endl;
		if(p1>=(p2-1)) break;
		if(v[p1+1]<=b){
			p1++;
			cout << "Db1: " << p1 << endl;
		}
	}
	int x1 = min(a+b, c), x2 = max(a+b, c);
	while(v[p2-1]>(x1)){
		if(p1>=(p2-1)) break;
		p2--;
		cnt++; cout << "Db: " << p2 << endl;
		if(p1>=(p2-1)) break;
		if(v[p1+1]<=x1) p1++;
	}
	REP(i, p1+1, p2){
		cnt++; cout << "Dbi: " << i << endl;
	}
	cout << cnt;
	return 0;
}
