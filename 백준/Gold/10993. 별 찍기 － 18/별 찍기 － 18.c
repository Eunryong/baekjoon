#include<stdio.h>
char arr[1030][2055];
int cnt;
void divide(int x, int y, int h, int w, int size) {
    if (size == 0) return;
    if (size % 2) {
        for (int i = 0; i < h; i++) {
            if (i == 0) {
                arr[i + x][w / 2 + y] = '*';
            } else if (i == h - 1) {
                for (int j = 0; j < w; j++) {
                    arr[i + x][j + y] = '*';
                }
            } else {
                arr[i + x][w / 2 - i + y] = '*';
                arr[i + x][w / 2 + i + y] = '*';
            }
        }
        divide(x + h / 2 , y + 1 * w / 4 + 1,(h - 1) / 2, w / 2 - 1, size - 1);
    } else {
        for (int i = 0; i < h; i++) {
            if (i == h - 1) {
                arr[i + x][w / 2 + y] = '*';
            } else if (i == 0) {
                for (int j = 0; j < w; j++) {
                    arr[i + x][j + y] = '*';
                }
            } else {
                arr[i + x][w / 2 - (h - i - 1) + y] = '*';
                arr[i + x][w / 2 + (h - i - 1) + y] = '*';
            }
        }

        divide(x + 1, y + 1 * w / 4 + 1,(h - 1) / 2, w / 2 - 1, size - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int h = 1;
    int w = 1;
    for (int i = 1; i < n; i++) {
        w = (w + 2) * 2 - 1;
        h = h * 2 + 1;
    }
    divide(0, 0, h, w, n);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < (n % 2 ? (w + 1) / 2 + i : w - i); j++) {
            printf("%c", arr[i][j] == 0 ? ' ' : arr[i][j]);
        }
        printf("\n");
    }
}