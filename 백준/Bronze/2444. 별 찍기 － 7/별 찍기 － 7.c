#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            printf(" ");
        }   
        for (int j = 0; j < i * 2 + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = 1; i < n; i++) {
        for (int j = n - i; j < n; j++) {
            printf(" ");
        }   
        for (int j = 0; j < (n - i - 1) * 2 + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}