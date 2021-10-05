//  Problem : :  Given the number, you are to answer the question: "Is it prime?"
/* Input :: t – the number of test cases, then t test cases follows. [t <= 500]
              Each line contains one integer: N [2 <= N <= 2^63-1] */
// Output ::  For each test case output string "YES" if given number is prime and "NO" otherwise.


///  Solution ::

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define M 1000000007
#define u64 uint64_t
#define u128 __uint128_t
bool check_composite(u64 n, u64 a, u64 d, int s);

// deterministic version of MillerRabin
bool isPrime(u64 n)
{
    if(n<2) return false;
    
    int r=0;
    u64 d=n-1;
    
    while((d&1)==0)   // if d is even
    {
        d>>=1;
        r++;
    }
    for(auto a:{2,3,5,7,11,13,17,19,23,29,31,37})
    {
        if(n==a) return true;
          if (check_composite(n, a, d, r))
        return false;
    }
    return true;
}

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};


int
main ()
{
  u64 t;
  cin >> t;
  while (t--)
    {
      u64 n;
      cin >> n;
      isPrime (n) ? cout << "YES\n" : cout << "NO\n";

    }
  return 0;
}

