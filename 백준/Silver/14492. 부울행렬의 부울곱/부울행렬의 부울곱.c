#include <stdio.h>
#define max(x, y) (x) > (y) ? (x) : (y)


int main() {
    int n;
    scanf("%d", &n);
    int A[n][n];
    int B[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum |= A[i][k] & B[k][j];
            }
            if (sum & 1) cnt++;
        }
    }
    printf("%d", cnt);
}