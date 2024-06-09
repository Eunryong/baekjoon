#include <stdio.h>
#include <memory.h>
#define div 1000000000

long long dp[1 << 10][101][10];

int main() {
    int n;
    scanf("%d", &n);
    if (n < 10) {
        printf("%d", 0);
        return 0;
    }
    for (int i = 1; i <= 9; i++) {
        dp[1 << i][1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int bit = 0; bit < (1 << 10); bit++) {
                dp[bit | (1 << j)][i][j] += ((j == 0 ? 0 : dp[bit][i - 1][j - 1]) + (j == 9 ? 0 : dp[bit][i - 1][j + 1])) % div;
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans += dp[(1 << 10) - 1][n][i];
        ans %= div;
    }
    printf("%lld", ans);
}