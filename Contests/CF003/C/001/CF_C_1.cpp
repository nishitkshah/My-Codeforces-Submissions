#include<iostream>
#include<string>
#include<vector>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

string s;
int n, cnt;
vector<char> v;

bool iO(char c){		//Is Opening
	if((c=='<')||(c=='{')||(c=='[')||(c=='(')) return true;
	return false;
}

bool chk(char a, char b){
	switch(a){
		case '<':
			if(b=='>') return true;
			return false;
		case '{':
			if(b=='}') return true;
			return false;
		case '[':
			if(b==']') return true;
			return false;
		case '(':
			if(b==')') return true;
			return false;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin >> s;
	n = s.size();
	cnt = 0;
	bool isVal = true;
	v.clear();
	if(!(n%2)){
		REP(i, 0, n){
			if(iO(s[i])) v.push_back(s[i]);
			else{
				if(v.size()==0){
					isVal = false;
					break;
				}
				if(!chk(v[v.size()-1], s[i])) cnt++;
				v.pop_back();
			}
		}
	}else isVal = false;
	if(isVal) cout << cnt;
	else cout << "Impossible";
	return 0;
}
