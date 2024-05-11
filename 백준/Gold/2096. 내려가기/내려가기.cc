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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int dp[6][2];
    for (int i = 0; i < 3; i++) {
        fill(dp[i], dp[i] + 2, 0);
    }
    for (int i = 3; i < 6; i++) {
        dp[i][0] = 0;
        fill(dp[i] + 1, dp[i] + 2, 1000001);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            int x;
            cin >> x;
            dp[j + 3][i % 2] = 1000001;
            for (int k = -1; k < 2; k++) {
                if (k + j < 0 || k + j > 2) continue;
                dp[j][i % 2] = max(dp[j][i % 2], dp[j + k][(i - 1) % 2] + x);
                dp[j + 3][i % 2] = min(dp[j + 3][i % 2], dp[j + 3 + k][(i - 1) % 2] + x);
            }
        }
    }
    cout << max({dp[0][N % 2], dp[1][N % 2], dp[2][N % 2]}) << " " << min({dp[3][N % 2], dp[4][N % 2], dp[5][N % 2]});
    return 0;
}