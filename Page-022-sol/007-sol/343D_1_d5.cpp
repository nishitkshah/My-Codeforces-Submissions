//17:32 02-06-2019 to 17:40 02-06-2019 - write set based solution
//22:15 03-06-2019
//22:38 03-06-2019
//22:39 03-06-2019
//22:42 03-06-2019
//23:29 03-06-2019 - referred to submissions 8530877 and 8531287
//23:45 03-06-2019

#include<iostream>
#include<set>
#include<vector>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 500010

int n, q, lk[N_]={0}, r[N_]={0}, cnt=1, par[N_]={0};	//l[x] is equal to x and hence skipped
vector<int> t[N_];
set<int> st;

void dfs(int nd, int pr=0){
par[cnt] = pr;
lk[nd] = cnt++;
for(auto nc: t[nd])
	if(nc!=pr){
		dfs(nc, nd);
		cnt++;
	}
r[nd] = cnt;
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n;
int a, b;
RE(i, 1, n){
	cin >> a >> b;
	t[a].push_back(b);
	t[b].push_back(a);
}
cnt = 1;
dfs(1);
cin >> q;
int c, v;
RE(i, 1, n+1) st.insert(i);
st.insert(N_);	//Added so that no lookup results in st.end()
RE(i, 0, q){
	cin >> c >> v;
	v = lk[v];
	int sv = *(st.lower_bound(v));
	switch(c){
		case 1:
			{
				bool isempty = false;
				while(sv<r[v]){
					isempty = true;
					st.erase(sv);
					sv = *(st.lower_bound(v));
				}
				if(isempty)
					st.insert(lk[par[v]]);
			}
			break;
		case 2:
			st.insert(v);
			break;
		case 3:
			if(sv<r[v]) cout << "0\n";
			else cout << "1\n";
			break;
	}
}
}

//22:37 03-06-2019
//22:38 03-06-2019
//22:40 03-06-2019
//22:42 03-06-2019
//23:44 03-06-2019
//23:48 03-06-2019
//23:49 03-06-2019
