#include<stdio.h>
char arr[6666][6666];

void divide(int x, int y, int size) {
    if (size >= 3) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 1 && j == 1) continue;
                divide(x + i * (size / 3), y + j * (size / 3) , size / 3);
            }
        }
    }
    if (size == 1)
        arr[x][y] = '*';
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = ' ';
        }
    }
    divide(0, 0, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}
