#include <stdio.h>
#include <memory.h>
#define max(x, y) (x) > (y) ? (x) : (y)

int lower_bound(int st, int en, int n, int arr[]) {
    while (en > st) {
        int mid = (st + en) / 2;
        if (n > arr[mid]) {
            st = mid + 1;
        } else {
            en = mid;
        }
    }
    return en;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    int ans[n];
    memset(ans, 0, sizeof(ans));
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (i == 0) ans[0] = arr[i];
        else {
            if (ans[cnt - 1] < arr[i]) {
                cnt++;
                ans[cnt - 1] = arr[i];
            } else {
                int idx = lower_bound(0, cnt, arr[i], ans);
                ans[idx] = arr[i];
            }
        }
    }
    printf("%d", cnt);
}