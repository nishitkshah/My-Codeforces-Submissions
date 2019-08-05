//18:50 16-05-2018
//18:58 16-05-2018
//19:02 16-05-2018
//19:04 16-05-2018

#include<iostream>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int main(){
	int m, s, sm[100], lrg[100];
	cin >> m >> s;
	if(s==0&&m==1){
		cout << "0 0\n";
		return 0;
	}
	if(!s||(s>(9*m))){
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
		lrg[p]++;
		st--;
		if(lrg[p]==9) p++;
	}
	REP(i, 0, m) cout << sm[i];
	cout << " ";
	REP(i, 0, m) cout << lrg[i];
	cout << "\n";
	return 0;
}

//18:56 16-05-2018
//18:59 16-05-2018
//19:03 16-05-2018
//19:05 16-05-2018
//19:05 16-05-2018 - submitted
