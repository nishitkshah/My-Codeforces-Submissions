//12:21 31-05-2018
//12:24 31-05-2018

#include<iostream>
#include<string>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

main(){
	int k, cnt[10], diff=0;
	string s;
	cin >> k >> s;
	REP(i, 0, s.size()) cnt[s[i]-'0']++;
	REP(i, 0, 9) k -= cnt[i]*i;
	REP(i, 0, 9){
		if(k>cnt[i]*(9-i)){
			k -= cnt[i]*(9-i);
			diff += cnt[i];
			cnt[9] += cnt[i];
			cnt[i] = 0;
		}else{
			diff += (k+9-i-1)/(9-i);
			break;
		}
	}
	cout << diff << "\n";
}

//12:33 31-05-2018
