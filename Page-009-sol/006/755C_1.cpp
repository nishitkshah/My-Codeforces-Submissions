//13:36 10-07-2018
//13:43 10-07-2018

#include<cstdio>
#include<algorithm>

using namespace std;

int n, p[10000], r[10000];

int root(int x){
	if(r[x]==-1) return x;
	r[x] = root(r[x]);
	return r[x];
}

bool st_union(int x, int y){
	x = root(x);
	y = root(y);
	if(x!=y){
		if(r[x]<=r[y])
			swap(x, y);
		r[y] -= r[x];
		r[x] = y;
		return true;
	}
	return false;
}

main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &(p[i]));
		p[i]--;
		r[i] = -1;
	}
	for(int i=0; i<n; i++)
		st_union(i, p[i]);
	int cnt = 0;
	for(int i=0; i<n; i++)
		if(r[i]<0) cnt++;
	printf("%d\n", cnt);
}

//13:56 10-07-2018
