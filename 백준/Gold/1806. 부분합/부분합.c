#include <stdio.h>
#include <stdbool.h>
#define min(x, y) (x) < (y) ? (x) : (y)
int main() {
    int arr[100001];
    int n;
    long long s;
    scanf("%d %lld", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int st = 0, en = 0, len = 100001;
    long long sum = 0;
    while (st <= en) {
        if (sum >= s) {
            len = min(len, en - st);
            sum -= arr[st];
            st++;
        }
        else if (en == n) break;
        else {
            sum += arr[en];
            en++;
        }
    }
    if (len == 100001) printf("0");
    else printf("%d", len);
}