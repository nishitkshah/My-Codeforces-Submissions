//09:24 30-10-2018
//09:30 30-10-2018
//09:59 30-10-2018
//10:04 30-10-2018
//21:38 30-10-2018
//23:56 30-10-2018

#include<iostream>
#include<utility>
#include<unordered_map>
#include<cstdlib>
#include<vector>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 2000
#define px first
#define py second

typedef pair<int, int> pii;
typedef vector<int> vi;

struct pairhash {
public:
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const
  {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};

unordered_map<pii, vi, pairhash> mp;

int n;
pii p[N_];

int gcd(int a, int b){
	if(!a || !b) return a+b;	//2 points don't coincide
	return gcd(b, a%b);
}

main(){
cin >> n;
RE(i, 0, n) cin >> p[i].px >> p[i].py;
long long ans=0LL;
RE(i, 0, n){
	mp.clear();
	RE(j, 0, n)
		if(i!=j){
			int dx=p[i].px-p[j].px, dy=p[i].py-p[j].py;
			int g = gcd(abs(dx), abs(dy));
			dx /= g, dy /= g;
			if(dx<0) dx *= -1, dy *= -1;
			if(dy<0) dx *= -1, dy *= -1;
			if(!mp.count({dx, dy})) mp[{dx, dy}] = vector<int>();
			mp[{dx, dy}].push_back(j);
		}
	for(auto const& x: mp){
		int l_sz = (x.second).size();
		ans += (n-1-l_sz)*l_sz;
	}
}
cerr << ans << '\n';
cout << ans/6 << '\n';
}

//09:58 30-10-2018
//09:59 30-10-2018
//10:05 30-10-2018
//21:38 30-10-2018
//23:57 30-10-2018
//23:59 30-10-2018
