#include<iostream>
#include<string>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

string s;
int n, p, q, x=-1, y=-1;

int main(){
	ios::sync_with_stdio(0);
	cin >> n >> p >> q;
	cin >> s;
	REP(i, 0, n+1)
		REP(j, 0, n+1)
			if((i*p+j*q)==n){
				x = i;
				y = j;
				break;
			}
	if(x==-1) cout << -1;
	else{
		cout << x+y << "\n";
		int ind=0;
		REP(i, 0, x){
			REP(j, 0, p){
				cout << s[ind++];
				ind++
			}
			cout << "\n";
		}
		REP(i, 0, y-1){
			REP(j, 0, q){
				cout << s[ind++];
				ind++
			}
			cout << "\n";
		}
		REP(j, 0, q){
			cout << s[ind++];
			ind++
		}
	}
	return 0;
}
