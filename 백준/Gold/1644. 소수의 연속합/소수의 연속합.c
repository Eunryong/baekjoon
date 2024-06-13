#include <stdio.h>
#define min(x, y) (x) < (y) ? (x) : (y)
int n;

int check(int num) {
    for (int i = 2; i <= num / i; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    scanf("%d", &n);
    int prime[n + 1];
    int prime_size = 0;
    int vis[n + 1];
    int arr[n + 1];
    for (int i = 0; i <= n; i++) {
        vis[i] = 0;
        arr[i] = 0;
    }
    long long sum = 0;
    int idx = 0;
    for (int i = 2; i <= n; i++) {
        if (vis[i] == 0 && check(i) == 1) {
            arr[i]++;
            sum += i;
            long long tmp = sum;
            if (sum <= n && prime_size) arr[sum]++;
            for (int j = idx; j < prime_size - 1; j++) {
                tmp -= prime[j];
                if (tmp <= n) {
                    arr[tmp]++;
                }
            }
            while (sum - prime[idx] > n && idx < prime_size) {
                sum -= prime[idx];
                idx++;
            }
            prime[prime_size++] = i;
            for (int j = 1; j <= n / i; j++) {
                vis[j * i] = 1;
            }
            
        }
    }
    printf("%d", arr[n]);
}
