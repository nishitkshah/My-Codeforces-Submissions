//19:37 08-08-2018
//19:39 08-08-2018

#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

main(){
	int n, a, b, c, d, s;
	pair<int, int> p[1000];
	cin >> n;
	RE(i, 0, n){
		cin >> a >> b >> c >> d;
		s = -(a+b+c+d);
		p[i] = {s, i};
	}
	sort(p, p+n);
	int rank;
	RE(i, 0, n){
		if(p[i].second==0){
			rank = i;
			break;
		}
	}
	cout << rank+1 << '\n';
}

//19:43 08-08-2018
//19:44 08-08-2018
