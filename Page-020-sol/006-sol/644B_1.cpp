//20:48 19-02-2019
//20:57 19-02-2019

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

int n, b, t[N_], d[N_], e[N_], et=0, ci=-1;
set< pair<int, pair<int, int> > > s;
queue<int> q;

main(){
cin >> n >> b;
RE(i, 0, n){
	cin >> t[i] >> d[i];
	s.push({t[i], {EN, i}});
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
			int ct = max(et, t[ci]);
			s.push({ct+d[ci], {EX, ci}});
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
RE(i, 0, n){
	if(i) cout << ' ';
	cout << e[i];
}
cout << '\n';
}

//22:01 19-02-2019
