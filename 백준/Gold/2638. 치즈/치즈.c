#include <stdio.h>
#include <memory.h>
#include <stdbool.h>

int size[101][101];
bool vis[101][101];
int arr[101][101];
int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int change_arr() {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (size[i][j] >= 2) {
                arr[i][j] = 0;
                ret++;
            }
        }
    }
    return ret;
}

void set_size() {
    int x_q[100100];
    int y_q[100100];
    int q_size = 1;
    int st = 0;
    x_q[0] = 0;
    y_q[0] = 0;
    
    while (q_size) {
        int next_size = 0;
        int idx = st + q_size;
        for (int i = 0; i < q_size; i++) {
            int x = x_q[st + i];
            int y = y_q[st + i];
            if (vis[x][y]) continue;
            vis[x][y] = 1;

            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (arr[nx][ny] == 1) size[nx][ny]++;
                else if (!vis[nx][ny]) {
                    x_q[idx] = nx;
                    y_q[idx] = ny;
                    idx++;
                    next_size++;
                }
            }
        }
        st += q_size;
        q_size = next_size;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    while (1) {
        memset(vis, 0, sizeof(vis));
        memset(size, 0, sizeof(size));
        
        set_size();
        if (change_arr() == 0) {
            break;
        } else {
            cnt++;
        }
    }
    printf("%d", cnt);
}