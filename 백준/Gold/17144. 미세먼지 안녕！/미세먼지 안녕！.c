#include <stdio.h>
#include <memory.h>
int r, c, t;
int arr[51][51];
int x[2555], y[2555];
int dust[2555];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int a_x[2] = {-1, -1};
void diffuse() {
    int size = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] > 0) {
                x[size] = i;
                y[size] = j;
                dust[size] = arr[i][j];
                size++;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        int div = 0;
        int n_dust = dust[i] / 5;
        for (int j = 0; j < 4; j++) {
            int nx = x[i] + dx[j];
            int ny = y[i] + dy[j];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c || arr[nx][ny] == -1) continue;
            arr[nx][ny] += dust[i] / 5;
            div++;
        }
        arr[x[i]][y[i]] -= n_dust * div;
    }
}

void clean() {
    int dir = 0;
    int n_x = a_x[0];
    int n_y = 0;
    int cur = 0;
    while (1) {
        int nx = n_x + dx[dir];
        int ny = n_y + dy[dir];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
            dir++;
            nx = n_x + dx[dir];
            ny = n_y + dy[dir];
        }
        if (arr[nx][ny] == -1) break;
        int tmp = arr[nx][ny];
        arr[nx][ny] = cur;
        cur = tmp;
        n_x = nx;
        n_y = ny;
    }
    dir = 4;
    n_x = a_x[1];
    n_y = 0;
    cur = 0;
    while (1) {
        int nx = n_x + dx[dir % 4];
        int ny = n_y + dy[dir % 4];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
            dir--;
            nx = n_x + dx[dir];
            ny = n_y + dy[dir];
        }
        if (arr[nx][ny] == -1) break;
        int tmp = arr[nx][ny];
        arr[nx][ny] = cur;
        cur = tmp;
        n_x = nx;
        n_y = ny;
    }
}

int main() {
    scanf("%d %d %d", &r, &c, &t);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);            
            if (arr[i][j] == -1) {
                int idx = a_x[0] == -1 ? 0 : 1;
                a_x[idx] = i;
            }
        }
    }
    while (t--) {
        diffuse();
        clean();
    }
    int ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] != -1) ans += arr[i][j];
        }
    }
    printf("%d", ans);
}