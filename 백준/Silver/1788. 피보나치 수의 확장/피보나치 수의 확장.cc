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

int dp[1000001];
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int len = abs(n);
    if (n == 0) {
        cout << 0 << "\n" << 0;
        return 0;
    }
    dp[1] = 1;
    for (int i = 2; i <= len; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= 1000000000;
    }
    cout << (n > 0 ? 1 : (len % 2 == 0 ? -1 : 1)) << "\n";
    cout << dp[len];
    return 0;
}