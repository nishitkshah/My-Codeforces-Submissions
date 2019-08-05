//20:18 19-08-2018
//20:26 19-08-2018

#include<iostream>
#include<unordered_map>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAX 200000

struct node{
	node* p[2];
	int cnt;

	node(){
		p[0] = p[1] = NULL;
		cnt = 0;
	}
};

int q, x;
char c;
node* trie=new node();

node* get_nd(int v){

node* n = trie;
for(int i=30; i>=0; i--){	//31 bits
	int b = (v&(1<<i)) ? 1 : 0;
	if(n->(p[b])==NULL)
		n->(p[b]) = new node();
	n = n->(p[b]);
}
return n;

}

void insert(int v){

node* n = get_nd(v);
(n->cnt)++;

}

void erase(int v, int bi=30, node* n=trie){

int b = (v&(1<<bi)) ? 1 : 0;
node* nxt = n->p[b];
n->p[b] = NULL;
if(!bi){
	erase(v, bi+1, nxt);	
}
if( ((n->p[0])==NULL) && ((n->p[1])==NULL) && ((n->cnt)==0) )
	delete(n);

}

void remove(int v){

node* n = get_nd(v);
(n->cnt)--;

if((n->cnt)==0){
	erase(v);
}

}

int query(int v){

node* n = trie;
int ret = 0;
for(int i=30; i>=0; i--){	//31 bits
	int b = (v&(1<<i)) ? 1 : 0;
	if((p[1-b])==NULL)
		b = 1-b;
	n = n->(p[1-b]);
	ret = 2*ret+(1-b);
}
return ret;

}

void solve(){

cin >> c >> x;

switch(c){
	case '+':
		insert(x);
		break;
	case '-':
		remove(x);
		break;
	case '?':
		cout << (x^query(x)) << '\n';
		break;
}

}

main(){

insert(0);
cin >> q;
RE(__t, 0, q){
	solve();
}

}

//21:18 19-08-2018
