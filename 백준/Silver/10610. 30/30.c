#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
int comp(char* a, char *b) {
    return *b - *a;
}

int main() {
    char n[100010];
    scanf("%s", &n);
    int cnt = 0;
    int sum = 0;
    int i = 0;
    while (n[i] != 0) {
        if (n[i] == '0') cnt++;
        sum += n[i] - '0';
        i++;
    }
    if (cnt == 0 || sum % 3 != 0) printf("-1");
    else {
        qsort(n, i, sizeof(char), comp);
        printf("%s", n);
    }
}