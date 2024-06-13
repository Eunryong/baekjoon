#include <stdio.h>
#define max(x, y) (x) > (y) ? (x) : (y)


int main() {
    int a_n, a_m;
    scanf("%d %d", &a_n, &a_m);
    int A[a_n][a_m];
    for (int i = 0; i < a_n; i++) {
        for (int j = 0; j < a_m; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    int b_n, b_m;
    scanf("%d %d", &b_n, &b_m);
    int B[b_n][b_m];
    for (int i = 0; i < b_n; i++) {
        for (int j = 0; j < b_m; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    for (int i = 0; i < a_n; i++) {
        for (int j = 0; j < b_m; j++) {
            int sum = 0;
            for (int k = 0; k < a_m && k < b_n; k++) {
                sum += A[i][k] * B[k][j];
            }
            printf("%d ", sum);
        }
        printf("\n");
    }
}