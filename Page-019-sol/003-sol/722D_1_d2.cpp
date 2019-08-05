//22:15 29-01-2019 to 22:22 29-01-2019 - Read question before. Read Editorial.
//18:13 31-01-2019
//18:49 31-01-2019
//22:47 31-01-2019

#include<iostream>
#include<algorithm>
#include<utility>
#include<set>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 50005

int n, y[N_], flag[N_]={0}, sp=0;
pair<int, int> s[20*N_];
set<int> st;

bool chk(int ind){
st.clear();
RE(i, 0, n) flag[i] = 0;
int cnt = 0;
for(int i=ind; i>=0; i--)
	if(!st.count(s[i].first))
		if(!flag[s[i].second]){
			cnt++;
			flag[s[i].second] = 1;
			st.insert(s[i].first);
		}
return cnt==n;
}

int b_search(){
int l=0, h=sp-1, m;
if(chk(l)) return l;
while(l<(h-1)){
	m = l+(h-l)/2;
	if(chk(m))
		h = m;
	else
		l = m;
}
return h;
}

main(){
cin >> n;
RE(i, 0, n){
	cin >> y[i];
	int t=y[i];
	while(t){
		s[sp++] = {t, i};
		t /= 2;
	}
}
cerr << "sp: " << sp << '\n';
sort(s, s+sp);
int ansi = b_search();
cerr << "ansi: " << ansi << '\n';
chk(ansi);
bool first = true;
for(auto v: st)
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
//23:04 31-01-2019
