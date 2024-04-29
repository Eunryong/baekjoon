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
int n, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    int max_speed = 0;
    vector<pair<int, int> > arr(n, make_pair(0, 0));
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        max_speed = max(max_speed, arr[i].second);
    }
    max_speed = max_speed * k + 1;
    vector<vector<int> > dp(k + 1, vector<int>(max_speed + 1, -1));
    dp[0][1] = 0;
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= max_speed; j++) {
            if (dp[i - 1][j] == -1) {
                continue;
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + j);
            ans = max(dp[i][j], ans);
            for (int l = 0; l < n; l++) {
                dp[i][j + arr[l].second] = max(dp[i][j + arr[l].second], dp[i - 1][j] - arr[l].first);
            }
        }
    }
    cout << ans;
    return 0;
}
