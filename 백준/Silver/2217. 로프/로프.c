#include<stdio.h>
#include<stdlib.h>

#define max(x, y) (x) > (y) ? (x) : (y)

int comp(void* a, void* b) {
    int a_n = *(int*)a;
    int b_n = *(int*)b;
    if (a_n > b_n) return 1;
    else if (a_n < b_n) return -1;
    else return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(arr[0]), comp);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, arr[i] * (n - i));
    }
    printf("%d", ans);
}