//22:15 29-01-2019 to 22:22 29-01-2019 - Read question before. Read Editorial.
//18:13 31-01-2019
//18:49 31-01-2019
//22:47 31-01-2019
//23:14 31-01-2019 - compared these 2 submissions - 21105528 and 21105812
//23:37 01-02-2019 - 722D_2.cpp
//23:49 01-02-2019

#include<iostream>
#include<algorithm>
#include<utility>
#include<set>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 50005

int n, y[N_];
set<int> c, x;

main(){
cin >> n;
RE(i, 0, n){
	cin >> y[i];
	c.insert(y[i]);
}
while(c.size()){
	int mx = *c.rbegin(), t;
	t = mx;
	while(t){
		if(!c.count(t)) break;
		t = t/2;
	}
	c.erase(mx);
	if(t)
		c.insert(t);
	else
		x.insert(mx);	//Note: mx and not t
}
bool first = true;
for(auto v: x)
	if(first){
		cout << v;
		first = false;
	}else
		cout << ' ' << v;
cout << '\n';
}

//18:47 31-01-2019
//18:50 31-01-2019
//23:04 31-01-2019
//23:15 31-01-2019
//23:48 01-02-2019
//23:49 01-02-2019
//23:52 01-02-2019
