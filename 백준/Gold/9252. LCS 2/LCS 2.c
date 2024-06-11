#include <stdio.h>
#include <string.h>
int dp[1002][1002];

#define max(x, y) (x) > (y) ? (x) : (y)
int main() {
    char buf[1001];
    char buf2[1001];
    scanf("%s", buf + 1);
    scanf("%s", buf2 + 1);
    int len = strlen(buf + 1), len2 = strlen(buf2 + 1);
    char ans[1001];
    int ans_size = 0;
    int ans_idx = 0;
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len2; j++) {
            if (buf[i] == buf2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int row = len, col = len2;
    while (row >= 1 && col >= 1 && dp[row][col]) {
        if (dp[row][col] == dp[row - 1][col]) {
            row--;
        } else if (dp[row][col] == dp[row][col - 1]) {
            col--;
        } else {
            ans[ans_size] = buf[row];
            ans_size++;
            row--; col--;
        }
    }
    printf("%d\n", ans_size);
    if (ans_size) {
        for (int i = ans_size - 1; i >= 0; i--) {
            printf("%c", ans[i]);
        }
    }
}