#include <stdio.h>

int main() {
    int idx = 1;
    while (1) {
        int r1, c1, r2, c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        if (r1 == 0 && c1 == 0 && r2 == 0 && c2 == 0) break;
        printf("Case #%d:\n", idx++);
        int arr1[r1][c1], arr2[r2][c2];
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                scanf("%d", &arr1[i][j]);
            }
        }
        for (int i = 0; i < r2; i++) {
            for (int j = 0; j < c2; j++) {
                scanf("%d", &arr2[i][j]);
            }
        }
        if (r1 != c2 && r2 != c1) printf("undefined\n");
        else {
            for (int i = 0; i < r1; i++) {
                printf("| ");
                for (int j = 0; j < c2; j++) {
                    int sum = 0;
                    for (int k = 0; k < c1 && k < r2; k++) {
                        sum += arr1[i][k] * arr2[k][j];
                    }
                    printf("%d ", sum);
                }
                printf("|\n");
            }
        }
    }
}