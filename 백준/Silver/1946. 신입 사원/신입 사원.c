#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int x;
    int y;
} rank;


int cmp(rank *a, rank *b) {
    return (*a).x - (*b).x;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        rank r[n];
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            r[i].x = x;
            r[i].y = y;
        }
        qsort(r, n, sizeof(rank), cmp);
        int ans = 1;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (r[i].y < r[cur].y) {
                ans++;
                cur = i;
            }
        }
        printf("%d\n", ans);
    }
}