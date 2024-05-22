#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n][n];
    int vis[n][n];
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    int x_q[500];
    int y_q[500];
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            vis[j][k] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 9) {
                x_q[0] = i;
                y_q[0] = j;
                arr[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }
    int size = 2;
    int eat_cnt = 0;
    int cnt = 0;
    int ans = 0;
    int front = 0;
    int last = 0;
    int arr_size = 1;
    int idx;
    int cur_x;
    int cur_y;
    while (arr_size) {
        int cur = eat_cnt;
        idx = last + 1;
        for (int i = 0; i < arr_size; i++) {
            int x = x_q[front + i];
            int y = y_q[front + i];
            if (arr[x][y] != 0 && arr[x][y] < size) {
                if (eat_cnt == cur) {
                    cur_x = x;
                    cur_y = y;
                    eat_cnt++;
                } else {
                    if (cur_x > x){
                        cur_x = x;
                        cur_y = y;
                    } else if (cur_x == x && y < cur_y) {
                        cur_x = x;
                        cur_y = y;
                    }
                }
            }
            if (cur != eat_cnt) continue;
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] > size || vis[nx][ny]) {
                    continue;
                }
                vis[nx][ny] = 1;
                x_q[idx] = nx;
                y_q[idx] = ny;
                idx++;
            }
        }
        if (cur != eat_cnt) {
            if (eat_cnt == size) {
                    eat_cnt = 0;
                    size++;
            }
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    vis[j][k] = 0;
                }
            }
            vis[cur_x][cur_y] = 1;
            arr[cur_x][cur_y] = 0;
            x_q[0] = cur_x;
            y_q[0] = cur_y;
            ans += cnt;
            front = 0;
            last = 0;
            idx;
            cnt = 0;
            arr_size = 1;
        } else {
            arr_size = idx - last - 1;
            front = last + 1;
            last = idx - 1;
            cnt++;
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         // printf("%d ", vis[i][j]);
    //         printf("%d ", arr[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d", ans);
}