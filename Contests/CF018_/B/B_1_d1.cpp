//21:16 18-04-2019
//21:18 18-04-2019
//21:29 18-04-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 510

int n, m, c[N_][N_];

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> m;
RE(i, 0, n)
	RE(j, 0, m) cin >> c[i][j];
int xr = 0, x=0, y=0;
RE(i, 0, n) xr ^= c[i][0];
if(!xr)
	RE(i, 0, n){
		RE(j, 1, m){
			int xrd = xr^c[i][0]^c[i][j];
			if(xrd){
				xr = xrd;
				x = i;
				y = j;
				break;
			}
		}
	}
if(xr){
	cout << "TAK\n";
	RE(i, 0, n){
		if(i==x) cout << y+1 << ' ';
		else cout << "1 ";
	}
	cout << '\n';
}else
	cout << "NIE\n";
}

//21:27 18-04-2019
//21:29 18-04-2019
//21:29 18-04-2019
