#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

int arr[51][51];
int n, m;
int x[200], h_x[2501];
int y[200], h_y[2501];
int size, h_size;
int ans = 1000000000;
int vis[51];
#define min(x, y) (x) < (y) ? (x) : (y)
void dfs(int cnt, int idx) {
    if (cnt == m) {
        int dis[2501];
        for (int i = 0; i < h_size; i++) dis[i] = 2501;
        for (int i = 0; i < size; i++) {
            if (vis[i]) {
                for (int j = 0; j < h_size; j++) {
                    dis[j] = min(dis[j], abs(x[i] - h_x[j]) + abs(y[i] - h_y[j]));
                }
            }
        }
        int tmp = 0;
        for (int i = 0; i < h_size; i++) {
            tmp += dis[i];
        }
        ans = min(ans, tmp);
    }
    for (int i = idx; i < size; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        dfs(cnt + 1, i + 1);
        vis[i] = 0;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 1) {
                h_x[h_size] = i;
                h_y[h_size] = j;
                h_size++;
            }
            if (arr[i][j] == 2) {
                x[size] = i;
                y[size] = j;
                size++;
            }
        }
    }
    dfs(0, 0);
    printf("%d", ans);
}