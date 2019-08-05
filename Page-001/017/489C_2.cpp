//18:50 16-05-2018

#include<iostream>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int main(){
	int m, s, sm[100], lrg[100];
	cin >> m >> s;
	if(!s){
		cout << "-1 -1\n";
		return 0;
	}
	REP(i, 0, m) sm[i] = lrg[i] = 0;
	int st = s;
	sm[0] = 1;
	st--;
	int p = m-1;
	while(st){
		sm[p]++;
		st--;
		if(sm[p]==9) p--;
	}
	st = s;
	p = 0;
	while(st){
		sm[p]++;
		st--;
		if(sm[p]==9) p++;
	}
	return 0;
}

//18:56 16-05-2018
