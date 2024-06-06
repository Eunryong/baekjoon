#include <stdio.h>
#include <memory.h>

int lower_bound(int st, int en, int n, int arr[]) {
    while (st < en) {
        int mid = (st + en) / 2;
        if (arr[mid] < n) {
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
    int LIS[n];
    int arr[n];
    int idx_arr[n];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (i == 0 || LIS[cnt - 1] < arr[i]) {
            LIS[cnt] = arr[i];
            idx_arr[i] = cnt;
            cnt++;
        } else {
            int idx = lower_bound(0, cnt, arr[i], LIS);
            LIS[idx] = arr[i];
            idx_arr[i] = idx;
        }
    }
    printf("%d\n", cnt);
    int find = cnt - 1;
    int ans[cnt];
    int idx = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (idx_arr[i] == find) {
            find--;
            ans[idx] = arr[i];
            idx++;
        }
    }
    for (int i = cnt - 1; i >= 0; i--) {
        printf("%d ", ans[i]);
    }
}