#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max(x, y) (x) > (y) ? (x) : (y)

int cmp(int *a, int *b) {
    return *b - *a;
}

int main() {
    int n;
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char tmp[9];
        scanf("%s", &tmp);
        int size = 1;
        for (int j = strlen(tmp) - 1; j >= 0; j--) {
            cnt[tmp[j] - 'A'] += size;
            size *= 10;
        }
    }
    qsort(cnt, 26, sizeof(int), cmp);
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += cnt[i] * (9 - i);
    }
    printf("%d", ans);
}