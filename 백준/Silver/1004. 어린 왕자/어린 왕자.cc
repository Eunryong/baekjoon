#include <stdio.h>
#include <math.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, st_x, st_y, en_x, en_y;
        scanf("%d %d %d %d %d", &st_x, &st_y, &en_x, &en_y, &n);
        int x, y, r;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &x, &y, &r);
            double st_dis = pow(pow(st_x - x, 2) + pow(st_y - y, 2), 0.5);
            double en_dis = pow(pow(en_x - x, 2) + pow(en_y - y, 2), 0.5);
            if (st_dis <= r && en_dis <= r) continue;
            else if (st_dis <= r) sum++;
            else if (en_dis <= r) sum++;
        }
        printf("%d\n", sum);
    }
}