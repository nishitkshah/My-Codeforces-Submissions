//11:29 14-08-2018
//11:34 14-08-2018

#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAX 100000

main(){
	int n, mx, a[MAX], s[MAX];
	cin >> n;
	RE(i, 0, n){
		cin >> a[i];
		s[i] = a[i];
	}
	sort(s, s+n);
	queue<int> q;
	mx = a[0];
	RE(i, 0, n){
		mx = max(mx, a[i]);
		if(mx==s[i])
			q.push(i+1);
	}
	cout << q.size() << '\n';
	bool space = false;
	while(q.size()){
		if(space) cout << ' ';
		else space = true;
		cout << q.front();
		q.pop();
	}
}

//11:40 14-08-2018
