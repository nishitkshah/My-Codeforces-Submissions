//18:24 21-10-2018
//18:28 21-10-2018
//18:42 21-10-2018

#include<iostream>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100

struct cup{
	int a, i, f;
};

bool cmp1(cup a, cup b){
	return a.a<b.a;
}

bool cmp2(cup a, cup b){
	return a.i<b.i;
}

int n, w;
cup c[N_];

main(){
cin >> n >> w;
int mn = 0;
RE(i, 0, n){
	cin >> c[i].a;
	c[i].i = i;
	c[i].f = (c[i].a+1)/2;
	mn += c[i].f;
}
if(mn>w){
	cout << "-1\n";
	return 0;
}
w -= mn;
sort(c, c+n, cmp1);
for(int i=n-1; i>=0; i--){
	if(!w) break;
	if(w < (c[i].a-c[i].f)){
		c[i].f += w;
		w = 0;
	}else{
		w -= c[i].a-c[i].f;
		c[i].f = c[i].a;
	}
}
sort(c, c+n, cmp2);
RE(i, 0, n){
	if(i) cout << ' ';
	cout << c[i].f;
}
cout << '\n';
}

//18:40 21-10-2018
//18:44 21-10-2018
//18:47 21-10-2018
