//Used code from: http://www.cplusplus.com/reference/functional/hash/

#include <iostream>
#include <functional>
#include <string>

int main ()
{
  char nts1[] = "Test";
  char nts2[] = "Test";
  std::string str1 (nts1);
  std::string str2 (nts2);

  std::hash<long long> ll_hash;

  std::cout << "hashes:\n";

  for(long long p=1LL; p<10000000000000000LL; p*=10LL){
    std::cout << "hash of " << 1*p << " and " << 2*p << ": " << ll_hash(p*1LL) << " " << ll_hash(p*2LL) << '\n';
  }

  return 0;
}
