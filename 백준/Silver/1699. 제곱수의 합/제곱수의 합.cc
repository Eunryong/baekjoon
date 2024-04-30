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
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
using namespace std;
int n;
int dp[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    fill(dp, dp + 100001, 100000);
    for (int i = 1; i <= n / i; i++) {
        dp[i * i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        if (dp[i] != 100000) continue;
        for (int j = 1; j <= n / j && j * j < i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout << dp[n];
    return 0;
}