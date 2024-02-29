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
int N, T;
int dp[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            int t;
            cin >> t;
            dp[i] = (i != 0 ? dp[i - 1] : 0) + t;
        }
        int ans = dp[0];
        for (int i = 1; i < N; i++) {
            ans = max(ans, dp[i]);
            for (int j = 0; j < i; j++) {
                ans = max(ans, dp[i] - dp[j]);
            }
        }
        fill_n(dp, 1001, 0);
        cout << ans << "\n";
    }
    return 0;
}