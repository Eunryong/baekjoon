#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <cmath>
using namespace std;

long long n;
map<long long, long long> m;
int mod = 1000000007;
long long fib(long long n) {
    if (m[n]) return m[n];
    long long result;
    if (n % 2 == 0) result = (fib(n/2) * (fib(n/2 + 1) + fib(n/2 - 1)) % mod) % mod;
    else result = ((fib((n+1) / 2) * (fib((n+1) / 2)) % mod + fib((n-1)/2)*fib((n-1)/2)) % mod) % mod;

    return m[n] = result % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    m[0] = 0;
    m[1] = 1;
    m[2] = 1;
    cout << fib(n);
    return 0;
}