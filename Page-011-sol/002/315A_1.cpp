//19:45 09-08-2018 - read before
//19:45 09-08-2018 - wrote code before

#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

main(){
	int n, p[100][2], cnt[1001], flag[1001]={0}, ans=0;	//forgot to initialize cnt last time
	cin >> n;
	RE(i, 0, n){
		cin >> p[i][0] >> p[i][1];
		cnt[p[i][0]]++;
	}
	RE(i, 0, n){
		int cl=p[i][0], op=p[i][1];	//this is wrong - realized after re-reading the statement
		if(cl!=op){
			if(cnt[op])
				flag[cl] = 1;
		}else{
			if(cnt[op]>1)
				flag[cl] = 1;
		}
	}
	RE(i, 0, 1001)
		if(!flag[i])
			ans += cnt[i];
	cout << ans << '\n';
}

//19:52 09-08-2018
