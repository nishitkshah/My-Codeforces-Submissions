//16:47 17-08-2018 to 17:02 17-08-2018
//17:39 17-08-2018

#include<iostream>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAX 10000001

int pr[MAX]={0}, pal[MAX]={0};

inline void gen_primes(){
	pr[0] = pr[1] = 1;
	RE(i, 2, MAX){
		if(pr[i]==0){
			for(int j=i; (i*j)<MAX; j++){
				pr[i*j] = 1;
			}
		}
	}
	//Reverse flag
	RE(i, 0, MAX){
		pr[i] = 1-pr[i];
	}
}

inline void gen_pal(){
	//Even length Palindromes
	RE(i, 0, MAX){
		int rem = i;
		long long rev = i;
		while(rem){
			rev = 10*rev + rem%10;
			rem /= 10;
		}
		if(rev<MAX){
			pal[(int)(rev)] = 1;
		}else{
			break;
		}
	}
	//Odd length Palindromes
	RE(i, 0, MAX){
		int rem = i;
		rem /= 10;
		long long rev = i;
		while(rem){
			rev = 10*rev + rem%10;
			rem /= 10;
		}
		if(rev<MAX){
			pal[(int)(rev)] = 1;
		}else{
			break;
		}
	}
}

main(){
	gen_primes();
	gen_pal();
	int p, q, mx=-1, cntpr=0, cntpal=0;
	cin >> p >> q;
	RE(i, 0, MAX){
		cntpr += pr[i];
		cntpal += pal[i];
		if((cntpr*q)<=(cntpal*p)){
			mx = i;
		}
	}
	if(mx==-1) cout << "Palindromic tree is better than splay tree\n";
	else cout << mx << '\n';
}

//18:15 17-08-2018
