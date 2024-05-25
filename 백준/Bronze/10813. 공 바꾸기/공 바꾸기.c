#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        int tmp = arr[x - 1];
        arr[x - 1] = arr[y - 1];
        arr[y - 1] = tmp;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}