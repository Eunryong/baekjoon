#include <stdio.h>

#define min(x, y) (x) > (y) ? (y) : (x)
#define max(x, y) (x) < (y) ? (y) : (x)
int arr[6];
int main() {
    int k;
    scanf("%d", &k);
    int max = 0;
    int idx = 0;
    for (int i = 0; i < 6; i++) {
        int dir;
        scanf("%d %d", &dir, &arr[i]);
    }
    for (int i = 0; i < 6; i++) {
        if (max < arr[i] * arr[(i + 1) % 6]) {
            max = arr[i] * arr[(i + 1) % 6];
            idx = i;
        }
    }
    printf("%d", k * (max - arr[(idx + 3) % 6] * arr[(idx + 4) % 6]));
}