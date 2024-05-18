#include <stdio.h>
#include <memory.h>
int main() {
    int n;
    scanf("%d", &n);
    long long dis[n - 1];
    long long l = 0;
    int p[n];
    for (int i = 0; i < n - 1; i++) {
        scanf("%lld", &dis[i]);
        l += dis[i];
    }
    long long ans = 0;
    int min_p = 1000000001;
    for (int i = 0; i < n - 1; i++) {
        scanf("%lld", &p[i]);
        if (min_p > p[i]) {
            ans += p[i] * dis[i];
            min_p = p[i];
        } else {
            ans += min_p * dis[i];
        }
    }
    printf("%lld", ans);
}