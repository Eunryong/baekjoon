#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int ans = 1;
    for (int i = n; i > 0; i--) {
        if (i <= 4 && i <= n - 4) {
            ans /= i;
        } else if (i <= 4 || i <= n - 4) {
            continue;
        } else {
            ans *= i;
        }
    }
    printf("%d", n < 4 ? 0 : ans);
}