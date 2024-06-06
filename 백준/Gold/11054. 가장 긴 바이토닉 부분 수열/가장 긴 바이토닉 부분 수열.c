#include <stdio.h>
#include <memory.h>
#define max(x, y) (x) > (y) ? (x) : (y)
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        max_val = max(max_val, arr[i]);
    }
    int dp[2][n][max_val + 500];
    memset(dp, 0, sizeof(dp));
    dp[0][0][arr[0]] = 1;
    dp[1][n - 1][arr[n - 1]] = 1;
    for (int i = 1; i < n; i++) {
        dp[0][i][arr[i]] = 1;
        for (int j = 0; j <= max_val; j++) {
            dp[0][i][j] = max(dp[0][i][j], dp[0][i - 1][j]);
            if (j < arr[i]) {
                dp[0][i][arr[i]] = max(dp[0][i][arr[i]], dp[0][i - 1][j] + 1);
            }
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        dp[1][i][arr[i]] = 1;
        for (int j = 0; j <= max_val; j++) {
            dp[1][i][j] = max(dp[1][i][j], dp[1][i + 1][j]);
            if (j < arr[i]) {
                dp[1][i][arr[i]] = max(dp[1][i][arr[i]], dp[1][i + 1][j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[0][i][arr[i]] + dp[1][i][arr[i]] - 1);
    }
    
    printf("%d", ans);
}