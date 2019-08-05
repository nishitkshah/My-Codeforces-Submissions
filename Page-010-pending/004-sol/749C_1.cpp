//20:20 06-08-2018
//20:25 06-08-2018

#include<iostream>
#include<queue>

using namespace std;

#define MAXN 200010
#define RE(a, b, c) for(int a=(b); a<(c); a++)

main(){
	int n, flag[MAXN]={0};
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
	int p=0;
	while((d.size()+r.size())!=1){	//Might give TLE
		if(!flag[p]){
			if(s[p]=='D'){
				flag[r.front()] = 1;
				r.pop();
			}else{
				flag[d.front()] = 1;
				d.pop();
			}
		}
		p = (p+1)%n;
	}
	if(d.size())
		cout << "D\n";
	else
		cout << "R\n";
}

//20:50 06-08-2018
