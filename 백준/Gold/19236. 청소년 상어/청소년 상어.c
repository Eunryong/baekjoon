#include <stdio.h>
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
#define max(x, y) (x) > (y) ? (x) : (y)
int ans = 0;
int arr[4][4];
int dir[4][4];

int move() {
    int size = 0;
    for (int n = 1; n <= 16; n++) {
        int i = 0, j = 0;
        int c = 0;
        for (int i = 0; c == 0 && i < 4; i++) {
            for (int j = 0; c == 0 && j < 4; j++) {
                if (arr[i][j] == n) {
                    size++;
                    for (int k = 0; k < 8; k++) {
                        int n_dir = (dir[i][j] + k) % 8;
                        int nx = i + dx[n_dir];
                        int ny = j + dy[n_dir];
                        if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && arr[nx][ny] != 99) {
                            arr[i][j] = arr[nx][ny];
                            dir[i][j] = dir[nx][ny];
                            arr[nx][ny] = n;
                            dir[nx][ny] = n_dir;
                            c = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
    return size;
}

void dfs(int x, int y, int d, int cnt) {
    cnt += arr[x][y];
    arr[x][y] = 99;
    dir[x][y] = -1;
    int arr_tmp[4][4], dir_tmp[4][4];

    if (move() == 0) {
        ans = max(ans, cnt);
        return;
    }

    arr[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            arr_tmp[i][j] = arr[i][j];
            dir_tmp[i][j] = dir[i][j];
        }
    }
   
    int c = 0;
    for (int i = 1; i <= 4; i++) {
        int nx = x + dx[d] * i;
        int ny = y + dy[d] * i;
        if (i == 1) {
            if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) {
                ans = max(ans, cnt);
                return;
            }
        }
        if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4 || arr[nx][ny] == 0 || arr[nx][ny] == 99) continue;
        c = 1;
        dfs(nx, ny, dir[nx][ny], cnt);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                arr[i][j] = arr_tmp[i][j];
                dir[i][j] = dir_tmp[i][j];
            }
        }
    }
    if (c == 0) ans = max(ans, cnt);
}

int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d %d", &arr[i][j], &dir[i][j]);
            dir[i][j]--;
        }
    }
    dfs(0, 0, dir[0][0], 0);
    printf("%d", ans);
}