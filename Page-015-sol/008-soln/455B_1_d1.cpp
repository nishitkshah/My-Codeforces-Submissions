//16:26 01-11-2018 - read editorial
//16:54 01-11-2018
//17:38 01-11-2018

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100000

struct node{
	bool w, l;
	int p[26];
	node(){
		w = false, l = false;
		RE(i, 0, 26) p[i] = 0;
	}
};

int n, k, p=2;
node tr[N_+2];

void addstr(){
string s;
cin >> s;
int l = s.size();
int cp=1;
RE(i, 0, l){
	if(!tr[cp].p[s[i]-'a']){
		tr[cp].p[s[i]-'a'] = p;
		tr[p] = node();
		p++;
	}
	cp = tr[cp].p[s[i]-'a'];
}
}

void dfs(int v){
int cnt=0;
RE(i, 0, 26)
	if(tr[v].p[i]){
		cnt++;
		int nv = tr[v].p[i];
		dfs(nv);
		tr[v].w = tr[v].w || ! tr[nv].w;
		tr[v].l = tr[v].l || ! tr[nv].l;
	}
if(!cnt)
	tr[v].w = false, tr[v].l = true;
}

main(){
tr[1] = node();
cin >> n >> k;
RE(i, 0, n)
	addstr();
dfs(1);
int win = 0;
if(tr[1].w){
	if(tr[1].l){
		cerr << "Path1\n";
		win = 1;
	}else{
		cerr << "PathMod\n";
		win = 2 - (k%2);
	}
}else{
	cerr << "Path2\n";
	win = 2;
}
RE(i, 0, 5){
	cerr << i << ": wl: ";
	cerr << tr[i].w << ' ' << tr[i].l << ": ";
	RE(j, 0, 26) cerr << tr[i].p[j] << ' ';
	cerr << '\n';
}
cerr << win << '\n';
cout << (win==1 ? "First\n" : "Second\n");
}

//17:37 01-11-2018
//17:55 01-11-2018
