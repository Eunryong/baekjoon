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
long long m, n;
long long dp[1001001];
map<long long, bool> ma;
int max_div;
void eratos() {
    
    for (int i = 2; i <= max_div; i++) {
        long long st = n % dp[i] == 0 ? n / dp[i] : n / dp[i] + 1;
        long long en = m / dp[i];
        while (st <= en) {
            ma[st * dp[i]] = true;
            st++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    long long i = 0;
    for (i = 1; i <= m / i; i++) {
        dp[i] = i * i;   
    }
    max_div = i - 1;
    eratos();
    
    cout << m - n - ma.size() + 1;
    return 0;
}