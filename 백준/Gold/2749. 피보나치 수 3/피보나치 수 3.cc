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

long long dp[1500001];
long long n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < 1500000;  i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000;
    }
    cin >> n;
    cout << dp[n % 1500000];

    return 0;
}