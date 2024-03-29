//19:19 17-02-2019 to 19:33 17-02-2019
//20:27 18-02-2019

#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 101
#define T_ 2001
#define INF 10000000

struct obj{
	int t, d, p, i;
}o[N_];

bool cmp(obj a, obj b){
if(a.d!=b.d) return a.d<b.d;
if(a.p!=b.p) return a.p<b.p;
if(a.t!=b.t) return a.t<b.t;
return a.i<b.i;
}

bool cmpi(obj a, obj b){
return a.i<b.i;
}

int n, tm[N_][T_], ind[N_][T_];

inline void init(){
RE(i, 0, N_)
	RE(j, 0, T_)
		tm[i][j] = INF, ind[i][j] = -1;
}

main(){
init();
cin >> n;
RE(i, 1, n+1){
	cin >> o[i].t >> o[i].d >> o[i].p;
	o[i].i = i;
}
sort(o+1, o+n+1, cmp);
tm[0][0] = 0; ind[0][0] = 0;
RE(i, 1, n+1){
	RE(j, o[i].p, T_){
		int ntm = tm[i-1][j-o[i].p]+o[i].t;
		if(ntm<tm[i-1][j] && ntm<o[i].d){
			tm[i][j] = ntm;
			ind[i][j] = o[i].i;
		}else{
			tm[i][j] = tm[i-1][j];
			ind[i][j] = ind[i-1][j];
		}
	}
}
sort(o+1, o+n+1, cmpi);
int mx = 0;
for(int i=T_-1, i>=0; i--)
	if(tm[n][i]<INF)
		mx = i;
cout << mx << '\n';
stack<int> st;
for(int i=n; i>0; i--){
	if(!mx)
		break;
	int v = ind[i][mx];
	st.push(v);
	mx -= o[v].p;
}
cout << st.size() << '\n';
while(st.size()){
	cout << st.top();
	st.pop();
	if(st.size()) cout << ' ';
	else cout << '\n';
}
}

//20:52 18-02-2019
