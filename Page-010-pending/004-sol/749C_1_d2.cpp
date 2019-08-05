//20:20 06-08-2018
//20:25 06-08-2018
//20:51 06-08-2018
//21:17 06-08-2018

#include<iostream>
#include<queue>

using namespace std;

#define MAXN 200010
#define RE(a, b, c) for(int a=(b); a<(c); a++)

main(){
	int n;
	char s[MAXN];
	queue<int> d, r;
	cin >> n;
	RE(i, 0, n){
		cin >> s[i];
		if(s[i]=='D')
			d.push(i);
		else
			r.push(i);
	}
	int p=n;
	while(d.size()!=0 && r.size()!=0){
		if(d.front()<r.front()){
			d.push(p++);
			d.pop();
			r.pop();
		}else{
			r.push(p++);
			d.pop();
			r.pop();
		}
	}
	if(d.size())
		cout << "D\n";
	else
		cout << "R\n";
}

//20:50 06-08-2018
//20:52 06-08-2018
//20:52 06-08-2018
//21:20 06-08-2018
