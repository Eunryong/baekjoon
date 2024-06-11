#include <stdio.h>
#define min(x, y) (x) < (y) ? (x) : (y)
#define max(x, y) (x) > (y) ? (x) : (y)
char n[1000001], m[1000001];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s %s", n, m);
        int c[2] = {0, 0};
        for (int i = 0; n[i]; i++) {
            if (n[i] != m[i]) {
                c[n[i] - '0']++;
            }
        }
        if (c[0] == c[1]) {
            printf("%d\n", c[0]);
        } else {
            printf("%d\n", max(c[0], c[1]));
        }
    }
}