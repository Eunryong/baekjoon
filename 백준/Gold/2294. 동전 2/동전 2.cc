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
int arr[101];
int dp[10001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    fill(dp, dp + 10001, 10001);
    sort(arr, arr + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = arr[i]; j <= k; j++) {
            if (j % arr[i] == 0) {
                dp[j] = min(dp[j - arr[i]] + 1, j / arr[i]);
            } else {
                dp[j] = min(dp[j], dp[j - arr[i]] + 1);
            }
        }
    }
    if (dp[k] == 10001) cout << -1;
    else cout << dp[k];
    return 0;
}