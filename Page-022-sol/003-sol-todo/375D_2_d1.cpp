//08:40 23-04-2019 to 08:53 23-04-2019
//22:12 24-04-2019
//22:47 24-04-2019
//22:01 27-05-2019 to 22:57 27-05-2019 and 23:09 30-05-2019
//00:18 31-05-2019

#include<iostream>
#include<vector>
#include<unordered_map>
#include<utility>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ (100 * 1001)

struct node{
int k, sz;
node *l, *r;
node(int val){
	k = val;
	sz = 1;
	l = r = NULL;
}
};

void rot(node* p, node* c){
if(!p || !c) return;
if(p->l == c){
	p->l = c->r;
	c->r = p;
}else{
	p->r = c->l;
	c->l = p;
}
}

void calc_sz(node* nd){
if(!nd) return;
nd->sz = 1;
if(nd->l) nd->sz += nd->l->sz;
if(nd->r) nd->sz += nd->r->sz;
}

void splay(node* &rt, int k){	//Returns node with value k. When such a node doesn't exist, it returns rightmost element smaller than k or leftmost element greater than k
//ToDo: Try to modify code to return rightmost node with value k (if it exists)
node *g=NULL, *p=NULL, *c=NULL;
g = rt;
if(!g || (g->k==k)) return;
if(g->k > k){
	p = g->l;
	if(!p) return;
	if(p->k == k){		//Can add more comparisons here to avoid code repetition later
		rot(g, p);
		rt = p;
		calc_sz(g); calc_sz(p); calc_sz(c);
		return;
	}
	if(p->k > k){
		splay(p->l, k);	//Important to splay before assigning to c as p->l can change here.
		c = p->l;
		if(c){
			rot(g, p);
			rot(p, c);
			rt = c;
			calc_sz(g); calc_sz(p); calc_sz(c);
			return;
		}else{
			rot(g, p);
			rt = p;
			calc_sz(g); calc_sz(p); calc_sz(c);
			return;
		}
	}else{
		splay(p->r, k);	//Important to splay before assigning to c as p->r can change here.
		c = p->r;
		if(c){
			rot(p, c);
			g->l = c;	//Note the extra step (needed before next rot of g and c)
			rot(g, c);
			rt = c;
			calc_sz(g); calc_sz(p); calc_sz(c);
			return;
		}else{
			rot(g, p);
			rt = p;
			calc_sz(g); calc_sz(p); calc_sz(c);
			return;
		}
	}
}else{
	p = g->r;
	if(!p) return;
	if(p->k == k){		//Can add more comparisons here to avoid code repetition later
		rot(g, p);
		rt = p;
		calc_sz(g); calc_sz(p); calc_sz(c);
		return;
	}
	if(p->k < k){	//Note that the operator is less than
		splay(p->r, k);	//Important to splay before assigning to c as p->r can change here.
		c = p->r;
		if(c){
			rot(g, p);
			rot(p, c);
			rt = c;
			calc_sz(g); calc_sz(p); calc_sz(c);
			return;
		}else{
			rot(g, p);
			rt = p;
			calc_sz(g); calc_sz(p); calc_sz(c);
			return;
		}
	}else{
		splay(p->l, k);	//Important to splay before assigning to c as p->l can change here.
		c = p->l;
		if(c){
			rot(p, c);
			g->r = c;	//Note the extra step (needed before next rot of g and c)
			rot(g, c);
			rt = c;
			calc_sz(g); calc_sz(p); calc_sz(c);
			return;
		}else{
			rot(g, p);
			rt = p;
			calc_sz(g); calc_sz(p); calc_sz(c);
			return;
		}
	}
}
}

void insert(node* &rt, int k){
splay(rt, k);
node* nw = new node(k);
if(rt->k < k){
	nw->l = rt;
	nw->r = rt->r;
	rt->r = NULL;
}else{
	nw->l = rt->l;
	nw->r = rt;
	rt->l = NULL;
}
calc_sz(rt); calc_sz(nw);
rt = nw;
}

void erase(node* &rt, int k){
splay(rt, k);
node* nrt;
if(rt->k != k) return;
if(rt->r){
	splay(rt->r, k-1);
	//rt->r->l will be NULL
	rt->r->l = rt->l;
	nrt = rt->r;
}else{
	nrt = rt->l;
}
delete(rt);
rt = nrt;
calc_sz(rt);
}

int cntGreaterThan(node* &rt, int k){
if(!rt) return 0;
splay(rt, k);
splay(rt->r, k-1);
if(rt->k > k) return 1 + ( rt->r ? rt->r->sz : 0);
else return cntGreaterThan(rt->r, k);
}

int n, m, c[N_], ans[N_], u, v;
vector<int> t[N_], q[N_], id[N_];
unordered_map<int, int> clc[N_];
node* cnc[N_];

int dfs(int nd, int par=-1){
int mx = nd, mn = -1;
for(auto nc: t[nd]){
	if(nc!=par){
		mn = dfs(nc, nd);
		if(clc[mx].size()<clc[mn].size()) swap(mx, mn);
		for(auto pii: clc[mn]){
			int ccr = 0;
			if(clc[mx].count(pii.first))
				ccr = clc[mx][pii.first];
			erase(cnc[mx], ccr);
			insert(cnc[mx], ccr+pii.second);
		}
	}
}
RE(i, 0, q[nd].size()){
	ans[id[nd][i]] = cntGreaterThan(cnc[mx], q[nd][i]-1);
}
return mx;
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> m;
RE(i, 1, n+1){
	cin >> c[i];
	clc[i][c[i]] = 1;
	cnc[i] = new node(1);
}
RE(i, 1, n){
	cin >> u >> v;
	t[u].push_back(v);
	t[v].push_back(u);
}
RE(i, 0, m){
	cin >> u >> v;
	q[u].push_back(v);
	id[u].push_back(i);
}
dfs(1);
}

//22:45 24-04-2019
//22:48 24-04-2019
//00:17 31-05-2019
//00:42 31-05-2019
