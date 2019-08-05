//20:55 15-05-2018
//20:58 15-05-2018

#include<iostream>
#include<algorithm>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

const int MAXN = 5010;

int a[MAXN], rs[MAXN], mx[MAXN];
int tree[18100];

void update(int x, int v, int ind = 0, int l = 0, int r = 8192){
	int mid = l + ((r-l)/2);
	tree[ind] = max(tree[ind], v);
	if(l==(r-1)) return;
	if(x<mid) update(x, v, 2*ind+1, l, mid);
	else update(x, v, 2*ind+2, mid, r);
}

int query(int x, int y, int ind = 0, int l = 0, int r = 8192){
	if(y>(r-1)) y = r-1;
	if(x<l) x = l;
	if(x>y) return -1;
	if((x==l)&&(y==(r-1))) return tree[ind];
	int mid = l + ((r-l)/2);
	int ans = query(x, y, 2*ind+1, l, mid);
	ans = max(ans, query(x, y, 2*ind+2, mid, r));
	return ans;
}

int main(){
	int n, q, l, r;
	cin >> n;
	REP(i, 1, n+1){
		cin >> a[i];
		rs[i] = rs[i-1]^a[i];
	}
	REP(j, 1, n+1){
		mx[j] = rs[j];
		REP(i, 0, j){
			mx[j] = max(mx[j], rs[j]^rs[i]);
		}
		update(j, mx[j]);
	}
	cin >> q;
	REP(i, 0, q){
		cin >> l >> r;
		cout << query(l, r) << "\n";
	}
	return 0;
}

//21:24 15-05-2018
