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
int T, W;
int dp[1001][3][31];
int arr[1001];
int ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T >> W;
    for (int i = 1; i <= T; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= T; i++) {
        dp[i][1][0] = dp[i - 1][1][0] + (arr[i] == 1 ? 1 : 0);
        for (int j = 1; j <= W && j <= i; j++) {
            if (arr[i] == 1) {
                dp[i][1][j] = max(dp[i - 1][1][j] + 1, dp[i - 1][2][j - 1] + 1);
                dp[i][2][j] = max(dp[i - 1][2][j], dp[i - 1][1][j - 1]);
            } else {
                dp[i][1][j] = max(dp[i - 1][1][j], dp[i - 1][2][j - 1]);
                dp[i][2][j] = max(dp[i - 1][2][j] + 1, dp[i - 1][1][j - 1] + 1);
            }
        }
    }
    ans = max(*max_element(dp[T][1] + 1, dp[T][1] + W + 1), *max_element(dp[T][2] + 1, dp[T][2] + W + 1));
    cout << ans;
    return 0;
}