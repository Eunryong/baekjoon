#include <stdio.h>
#include <stdbool.h>
#define max(x, y) (x) > (y) ? (x) : (y)
int main() {
    long long sum = 0;
    int n;
    long long k = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        long long tmp;
        scanf("%lld", &tmp);
        if (n == 1 && tmp == 1) {
            printf("Happy");
            return 0;
        }
        k = max(tmp, k);
        sum += tmp;
    }
    if (k <= sum / 2) printf("Happy");
    else printf("Unhappy");
}