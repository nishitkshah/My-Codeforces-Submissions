//12:21 31-05-2018
//12:24 31-05-2018
//12:35 31-05-2018
//18:29 31-05-2018
//18:34 31-05-2018

#include<iostream>
#include<string>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

main(){
	int k, cnt[10]={0}, diff=0, sm=0;
	string s;
	cin >> k >> s;
	REP(i, 0, s.size()) cnt[s[i]-'0']++;
	REP(i, 0, 10){ k -= cnt[i]*i; sm += cnt[i]*i;}
	REP(i, 0, 10) cerr << cnt[i] << " " << i << endl;
	cerr << s.size() << " " << sm << endl; 
	REP(i, 0, 10){
		if(k<=0) break;
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
//12:36 31-05-2018
//18:30 31-05-2018
//18:39 31-05-2018
