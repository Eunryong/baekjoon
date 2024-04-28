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
pair<int, int> arr[101];
int dp[101][5001];
bool check[5001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> arr[i].first >> arr[i].second;
    }
    check[1] = 1;
    for (int i = 1; i <= k; i++) {
        queue<int> q;
        for (int j = 1; j <= 5000; j++) {
            if (check[j] == true) {
                dp[i][j] = dp[i - 1][j] + j;
            }
            for (int k = 1; k <= n; k++) {
                if (dp[i - 1][j] < arr[k].first) {
                    continue;
                } else {
                    dp[i][j + arr[k].second] = max(dp[i - 1][j + arr[k].second], dp[i - 1][j] - arr[k].first);
                    q.push(j + arr[k].second);
                }
            }
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            check[x] = 1;
        }
    }
    cout << *max_element(dp[k], dp[k] + 5001);
    return 0;
}