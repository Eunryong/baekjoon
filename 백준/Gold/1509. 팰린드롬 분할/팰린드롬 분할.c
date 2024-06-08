#include <stdio.h>
#include <memory.h>
#define min(x, y) (x) < (y) ? (x) : (y)
int dp[2501][2501];
char buf[2501];
int size[2501];
int main() {
    scanf("%s", buf);
    int ans = 2500;
    for (int i = 0; i < strlen(buf); i++) {
        dp[i][i] = 1;
        for (int j = 0; j < i; j++) {
            if (buf[j] == buf[i] && (dp[i - 1][j + 1] == 1 || j == i - 1)) {
                dp[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < strlen(buf); i++) {
        size[i] = i == 0 ? 1 : size[i - 1] + 1;
        for (int j = 0; j < i; j++) {
            if (dp[i][j]) {
                size[i] = min(size[i], j == 0 ? 1 : size[j - 1] + 1);
            }
        }
    }
    printf("%d", size[strlen(buf) - 1]);
}