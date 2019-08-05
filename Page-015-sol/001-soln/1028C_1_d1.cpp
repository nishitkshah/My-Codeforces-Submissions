//22:58 22-10-2018
//23:21 22-10-2018
//00:02 23-10-2018

#include<iostream>
#include<map>
#include<vector>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 132674
#define MILL 1000000

struct rect{
int x1, y1, x2, y2;
};

int n, pre[MILL]={0};
rect r[N_];
map<int, int> m;

main(){
cin >> n;
RE(i, 0, n) cin >> r[i].x1 >> r[i].y1 >> r[i].x2 >> r[i].y2;
RE(i, 0, n) m[r[i].x1]=0, m[r[i].y1]=0, m[r[i].x2]=0, m[r[i].y2]=0;
int ct=0;
for(auto p: m)
	m[p.first] = ct++;
RE(i, 0, n) r[i].x1=m[r[i].x1], r[i].y1=m[r[i].y1], r[i].x2=m[r[i].x2], r[i].y2=m[r[i].y2];
vector<int> x, y;
RE(i, 0, n) pre[r[i].x1]++, pre[r[i].x2+1]--;
RE(i, 1, ct+1) pre[i] += pre[i-1];
RE(i, 0, ct+1){
/*	Wont work:
	if(pre[i]>=(n-1) && ( !i || pre[i-1]<(n-1) )) x.push_back(i);
	if(pre[i]>=(n-1) && pre[i+1]<(n-1)) x.push_back(i);
*/
	if(pre[i]>=(n-1) && ( !i || pre[i-1]!=pre[i] )) x.push_back(i);
	if(pre[i]>=(n-1) && pre[i+1]!=pre[i]) x.push_back(i);
}
RE(i, 0, ct+1) pre[i] = 0;
RE(i, 0, n) pre[r[i].y1]++, pre[r[i].y2+1]--;
RE(i, 1, ct+1) pre[i] += pre[i-1];
RE(i, 0, ct+1){
/*	Wont work:
	if(pre[i]>=(n-1) && ( !i || pre[i-1]<(n-1) )) y.push_back(i);
	if(pre[i]>=(n-1) && pre[i+1]<(n-1)) y.push_back(i);
*/
	if(pre[i]>=(n-1) && ( !i || pre[i-1]!=pre[i] )) y.push_back(i);
	if(pre[i]>=(n-1) && pre[i+1]!=pre[i]) y.push_back(i);
}
int xr=-1, yr=-1;
for(auto xi: x)
	for(auto yi: y){
		int cnt = 0;
		RE(i, 0, n){
			if(r[i].x1<=xi && xi<=r[i].x2 && r[i].y1<=yi && yi<=r[i].y2)
				cnt++;
		}
		if(cnt>=(n-1)) xr=xi, yr=yi;
	}
for(auto p: m)
	if(p.second==xr){
		xr = p.first;
		break;
	}
for(auto p: m)
	if(p.second==yr){
		yr = p.first;
		break;
	}
cout << xr << ' ' << yr << '\n';
}

//00:00 23-10-2018
//00:05 23-10-2018
//00:14 23-10-2018
