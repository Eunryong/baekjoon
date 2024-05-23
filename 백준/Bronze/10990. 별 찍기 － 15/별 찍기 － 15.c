#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            for (int j = 0; j < n - 1; j++) {
                printf(" ");
            }
            printf("*");
        } else {
            for (int j = 0; j < n - i - 1; j++) {
                printf(" ");
            }
            printf("*");
            for (int j = 0; j < (i - 1) * 2 + 1; j++) {
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }
}