#include <stdio.h>
#include <memory.h>
#define max(x, y) (x) > (y) ? (x) : (y)
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    int dp[n][1010];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        dp[i][arr[i]] = 1;
        for (int j = 0; i != 0 && j < 1001; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j > arr[i]) {
                dp[i][arr[i]] = max(dp[i][arr[i]], dp[i - 1][j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 1001; i++) {
        ans = max(ans, dp[n - 1][i]);
    }
    printf("%d", ans);
}