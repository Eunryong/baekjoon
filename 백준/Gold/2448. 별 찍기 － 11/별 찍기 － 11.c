#include <stdio.h>
char arr[4444][8888];
void divide(int x, int y, int h, int w) {
    if (h > 3 && w > 5) {
        divide(x, y + 1 * (w / 4), h / 2, w / 2);
        divide(x + 1 * (h / 2), y + 1 * (w / 2), h / 2, w / 2);
        divide(x + 1 * (h / 2), y, h / 2, w / 2);
    } else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == 0 && j != 2) continue;
                if (i == 1 && j % 2 == 0) continue;
                arr[x + i][y + j] = '*';
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    divide(0, 0, n, n * 2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 2; j++) {
            printf("%c", (arr[i][j] == 0 ? ' ': arr[i][j]));
        }
        printf("\n");
    }
}
