#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)
#define X first
#define Y second

typedef pair<int, int> pii;

int n, x, y, lr[2]={0, 0};
vector<pii> v;
int xy[4] = {1, 0, 0, 1};
int yx[4] = {0, 1, 1, 0};

int main(){
	cin  >> n;
	REP(i, 0, n+1){
		cin >> x >> y;
		v.push_back({x, y});
	}
	v.push_back(v[1]);
	REP(i, 1, v.size()-1){
		pii p1=v[i-1], p2=v[i], p3=v[i+1];
		int ind = 0;
		if(p1.X==p2.X){
			if(p1.Y>p2.Y) ind++;
			ind = ind<<1;
			if(p2.X>p3.X) ind++;
			lr[yx[ind]]++;
		}else{
			if(p1.X>p2.X) ind++;
			ind = ind<<1;
			if(p2.Y>p3.Y) ind++;
			lr[xy[ind]]++;
		}
	}
	cout << min(lr[0], lr[1]);
	return 0;
}
