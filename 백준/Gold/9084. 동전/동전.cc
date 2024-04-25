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
#include <set>
using namespace std;
int n, k, T;
int dp[10001];
int arr[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        cin >> k;
        for (int i = 1; i <= n; i++) {
            if (arr[i] <= k) {
                dp[arr[i]]++;
                for (int j = arr[i]; j <= k; j++) {
                    dp[j] += dp[j - arr[i]];
                }
            }
        }
        cout << dp[k] << "\n";
        fill(arr, arr + n + 1, 0);
        fill(dp, dp + k + 1, 0);
    }
    return 0;
}