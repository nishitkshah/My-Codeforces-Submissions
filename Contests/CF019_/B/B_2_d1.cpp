//20:22 01-05-2019
//20:26 01-05-2019
//21:04 01-05-2019
//21:20 01-05-2019
//21:40 01-05-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

int t, uc;
string s;
set<char> st;
char c[27], cs[27], cnt[27]={0};

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> t;
RE(i, 0, t){
	st.clear();
	RE(i, 0, 27) cnt[i] = 0;
	cin >> s;
	for(char ch: s){
		st.insert(ch);
		cnt[ch-'a']++;
	}
	uc = st.size();
	auto it = st.begin();
	RE(i, 0, uc){
		c[i] = *it;
		it++;
	}
	bool val = false;
	if(uc>6){
		val = true;
		int m = (uc+1)/2;
		RE(i, 0, m)
			cs[2*i] = c[i];
		RE(i, m, uc)
			cs[2*(i-m)+1] = c[i];
		//RE(i, 0, uc)
		//	cerr << cs[i] << ' ' << c[i] << '\n';
	}else{
		do{
			bool passed = true;
			RE(i, 0, uc-1)
				if(abs((int)c[i]-(int)c[i+1])==1)
					passed = false;
			if(passed){
				val = true;
				RE(i, 0, uc) cs[i] = c[i];
				break;
			}
		}while(next_permutation(c, c+uc));
	}
	if(val){
		RE(i, 0, uc)
			RE(j, 0, cnt[cs[i]-'a'])
				cout << cs[i];
		cout << '\n';
	}else
		cout << "No answer\n";
}
}

//20:31 01-05-2019
//21:08 01-05-2019
//21:37 01-05-2019
//21:49 01-05-2019
//21:49 01-05-2019
