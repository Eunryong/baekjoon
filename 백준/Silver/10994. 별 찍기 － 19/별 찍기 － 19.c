#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int size = 1;
    for (int i = 1; i < n; i++) {
        size = size + 4;
    }
    for (int i = 0; i < size / 2 + 1; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < i / 2; j++) {
                printf("* ");
            }
            for (int j = 0; j < size - i * 2; j++) {
                printf("*");
            }
            for (int j = 0; j < i / 2; j++) {
                printf(" *");
            }
        } else {
            for (int j = 0; j < (i + 1) / 2; j++) {
                printf("* ");
            }
            for (int j = 0; j < size - (i + 1) * 2; j++) {
                printf(" ");
            }
            for (int j = 0; j < (i + 1) / 2; j++) {
                printf(" *");
            }
        }
        printf("\n");
    }
    for (int i = size / 2 - 1; i >= 0; i--) {
        if (i % 2 == 0) {
            for (int j = 0; j < i / 2; j++) {
                printf("* ");
            }
            for (int j = 0; j < size - i * 2; j++) {
                printf("*");
            }
            for (int j = 0; j < i / 2; j++) {
                printf(" *");
            }
        } else {
            for (int j = 0; j < (i + 1) / 2; j++) {
                printf("* ");
            }
            for (int j = 0; j < size - (i + 1) * 2; j++) {
                printf(" ");
            }
            for (int j = 0; j < (i + 1) / 2; j++) {
                printf(" *");
            }
        }
        printf("\n");
    }
}
