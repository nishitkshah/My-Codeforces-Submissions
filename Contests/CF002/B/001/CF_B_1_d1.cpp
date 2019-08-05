#include<iostream>
#include<string>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)
#define MAX 200002

int la[MAX], lb[MAX];

int main(){
	ios::sync_with_stdio(0);
	string a, b;
	cin >> a >> b;
	REP(i, 0, MAX) la[i] = lb[i] = 0;
	REP(i, 0, a.size()){
		la[i] = a[i]-'0';
		if(i) la[i] += la[i-1];
	}
	REP(i, 0, b.size()){
		lb[i] = b[i]-'0';
		if(i) lb[i] += lb[i-1];
	}
	long long sum = 0;
	if(a[0]=='0') sum += lb[b.size()-a.size()];
	else sum += b.size()-a.size()+1-lb[b.size()-a.size()];
	REP(i, 1, a.size()){
		if(a[i]=='0') sum += lb[b.size()-a.size()+i]-lb[i-1];
		else sum += (b.size()-a.size()+1)-(lb[b.size()-a.size()+i]-lb[i-1]);
	}
	cout << sum;
	return 0;
}

