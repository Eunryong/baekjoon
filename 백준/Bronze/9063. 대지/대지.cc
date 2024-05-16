#include <stdio.h>
#include <math.h>

#define min(x, y) (x) < (y) ? (x) : (y)
#define max(x, y) (x) < (y) ? (y) : (x)

int main() {
    int n;
    scanf("%d", &n);
    int min_x = 10001, min_y = 10001, max_x = -10001, max_y = -10001;
    while (n--) {
        int x, y;
        scanf("%d %d", &x, &y);
        min_x = min(min_x, x);
        max_x = max(max_x, x);
        min_y = min(min_y, y);
        max_y = max(max_y, y);
    }
    printf("%d", (max_x - min_x) * (max_y - min_y));
}