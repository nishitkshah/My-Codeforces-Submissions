//19:45 09-08-2018 - read before
//19:45 09-08-2018 - wrote code before
//19:53 09-08-2018
//20:07 09-08-2018 - 315A_2.cpp
//20:21 09-08-2018

#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

main(){
	int n, p[100][2], flag[100]={0}, ans=0;
	cin >> n;
	RE(i, 0, n){
		cin >> p[i][0] >> p[i][1];
	}
	RE(i, 0, n){
		int op=p[i][0], cl=p[i][1];
		RE(j, 0, n){
			if(i!=j)
				if(p[j][0]==cl)
					flag[j] = 1;
		}
	}
	RE(i, 0, n)
		if(!flag[i])
			ans++;
	cout << ans << '\n';
}

//19:52 09-08-2018
//19:54 09-08-2018
//20:16 09-08-2018
//20:22 09-08-2018
//20:22 09-08-2018
