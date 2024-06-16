#include <stdio.h>
long long d[55];
long long sum(long long x) {
    long long ret = x & 1;
    int i = 54;
    while (i > 0) {
         if (x & (1LL << i)) {
            ret += d[i - 1] + (x - (1LL << i) + 1);
            x -= 1LL << i;
        }
        i--;
    }
    return ret;
}

int main() {
    long long st, en;
    scanf("%lld %lld", &st, &en);
    d[0] = 1;
    for (int i = 1; i < 55; i++) {
        d[i] = d[i - 1] * 2 + (1LL << i);
    }
    printf("%lld", sum(en) - sum(st - 1));
}