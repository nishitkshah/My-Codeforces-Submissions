//10:35 14-08-2018
//10:42 14-08-2018

#include<iostream>
#include<queue>

using namespace std;

queue<int> q;

int divide(int l, int r){
	if(l==r){
		q.push(l);
		return 1;
	}
	if(l==(r-1)){
		q.push(l);
		q.push(r);
		q.push(l);
		return 3;
	}
	int ans = 2;
	int m = l+(r-l)/2;
	q.push(m);
	ans += divide(l, m-1);
	ans += divide(m+1, r);
	q.push(m);
	return ans;
}

main(){
	int n;
	cin >> n;
	cout << divide(1, n) << '\n';
	bool space = false;
	while(q.size()){
		if(space){
			cout << ' ';
		}else{
			space = true;
		}
		cout << q.front();
		q.pop();
	}
}

//10:53 14-08-2018
//10:55 14-08-2018
