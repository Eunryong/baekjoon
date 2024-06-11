#include <stdio.h>
#include <stdbool.h>
int arr[9][9];
int size;
int x_q[81];
int y_q[81];

bool check(int x, int y, int val) {
    for (int i = 0; i < 9; i++) {
        if (i == x) continue;
        if (arr[i][y] == val) return false;
    }
    for (int i = 0; i < 9; i++) {
        if (i == y) continue;
        if (arr[x][i] == val) return false;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == x && j == y) continue;
            if (arr[(x / 3 * 3) + i][(y / 3 * 3) + j] == val) return false;
        }
    }
    return true;
}

bool dfs(int idx) {
    if (idx == size) {
        return true;
    }
    int n_x = x_q[idx];
    int n_y = y_q[idx];
    for (int i = 1; i < 10; i++) {
        if (check(n_x, n_y, i)) {
            arr[n_x][n_y] = i;
            if (dfs(idx + 1)) return true;
            arr[n_x][n_y] = 0;
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < 9; i++) {
        char tmp[10];
        scanf("%s", &tmp);
        for (int j = 0; j < 9; j++) {
            arr[i][j] = tmp[j] - '0';
            if (arr[i][j] == 0) {
                x_q[size] = i;
                y_q[size] = j;
                size++;
            }
        }
    }
    dfs(0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
}