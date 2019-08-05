//20:48 19-02-2019
//20:57 19-02-2019
//22:02 19-02-2019
//22:10 19-02-2019
//22:18 19-02-2019
//22:45 19-02-2019 - Compared codes: https://codeforces.com/contest/644/submission/45912196 and https://codeforces.com/contest/644/submission/45911957

#include<iostream>
#include<queue>
#include<utility>
#include<set>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 200000
#define EN 1
#define EX -1
//EX has to be less than EN for set ordering

int n, b, ci=-1;
long long t[N_], d[N_], e[N_], et=0LL;
set< pair<long long, pair<int, int> > > s;
queue<int> q;

main(){
cin >> n >> b;
RE(i, 0, n){
	cin >> t[i] >> d[i];
	s.insert({t[i], {EN, i}});
}
while(s.size()){
	auto piii = *s.begin();
	s.erase(s.begin());
	if(piii.second.first==EN){
		if(piii.first<et){
			if(q.size()<b)
				q.push(piii.second.second);
			else
				e[piii.second.second] = -1;
		}else{
			//ci has to be -1 as Exit event has been processed
			q.push(piii.second.second);
			ci = q.front();
			q.pop();
			long long ct = max(et, t[ci]);
			s.insert({ct+d[ci], {EX, ci}});
			e[ci] = ct+d[ci];
			et = e[ci];
		}
	}else{
		ci = -1;
		/*
		*if(q.size()){
		*	ci = q.front();
		*	q.pop();
		*	s.push({et+d[ci], {EX, ci}});
		*	e[ci] = et+d[ci];
		*}else{
		*	ci = -1;
		*}
		*/
	}
}
while(q.size()){
	ci = q.front();
	q.pop();
	//int ct = max(et, t[ci]);	//Not needed as all processes have entered before et
	e[ci] = et+d[ci];
	et = e[ci];
}
RE(i, 0, n){
	if(i) cout << ' ';
	cout << e[i];
}
cout << '\n';
}

//22:01 19-02-2019
//22:03 19-02-2019
//22:14 19-02-2019
//22:22 19-02-2019
//22:50 19-02-2019
//22:51 19-02-2019
