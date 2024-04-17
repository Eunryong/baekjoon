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
int N;
int p[16], t[16], dp[16][6];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> t[i] >> p[i];
    }
    for (int i = 1; i <= N; i++) {
        dp[i][0] = dp[i - 1][0];
        for (int j = 0; j <= 5; j++) {
            if (j == 0) {
                dp[i][t[i] - 1] = max(dp[i][t[i] - 1], dp[i][j] + p[i]);
            } else {
                dp[i][j - 1] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    cout << dp[N][0];
    return 0;
}