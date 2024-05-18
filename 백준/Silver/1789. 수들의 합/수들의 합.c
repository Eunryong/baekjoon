#include<stdio.h>

int main() {
    unsigned int s;
    scanf("%d", &s);
    long sum = 0;
    int i;
    for (i = 1; sum < s; i++) {
        sum += i;
    }
    printf("%d", sum == s ? i - 1 : i - 2);
}