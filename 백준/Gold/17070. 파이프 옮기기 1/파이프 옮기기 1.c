#include<stdio.h>
#include<memory.h>

int main() {
    int n;
    scanf("%d", &n);
    int dp[n + 1][n + 1][3];
    int arr[n + 1][n + 1];
    memset(arr, 0, sizeof(arr));
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    dp[1][2][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == 1) continue;
            if (i == 1 && j == 2) continue;
            dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
            dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
            if (arr[i][j - 1] == 0 && arr[i - 1][j] == 0) {
                dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
            }
        }
    }
    printf("%d ", dp[n][n][0] + dp[n][n][1] + dp[n][n][2]);
}