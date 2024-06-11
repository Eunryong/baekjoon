#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    bool vis[m + 1];
    memset(vis, 0, sizeof(vis));
    int idx[m + 1];
    for (int i = 0; i < n; i++) {
        int size;
        scanf("%d", &size);
        for (int j = 0; j < size; j++) {
            int tmp;
            scanf("%d", &tmp);
            if (vis[tmp]) {
                idx[tmp] = -1;
            } else {
                vis[tmp] = 1;
                idx[tmp] = i;
            }
        }
    }
    int cur[m + 1];
    int cur_size = 0;
    for (int i = 1; i <= m; i++) {
        if (vis[i] == 0) {
            cur_size = n;
            break;
        }
        if (idx[i] == -1) continue;
        else {
            bool c = 0;
            for (int j = 0; j < cur_size; j++) {
                if (cur[j] == idx[i]) c = 1;
            }
            if (c == 0) {
                cur[cur_size] = idx[i];
                cur_size++;
            }
        }
    }
    if (cur_size == n) printf("0");
    else printf("1");
}