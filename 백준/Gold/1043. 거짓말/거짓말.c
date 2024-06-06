#include<stdio.h>
#include<memory.h>
#define max(x, y) (x) > (y) ? (x) : (y)

int arr[51];
int board[51][51];
int check[51];
int vis[51];
int size[51];
int idx_size[51];
int idx[51][51];

void dfs(int n) {
    if (vis[n]) return;
    vis[n] = 1;
    for (int i = 0; i < size[n]; i++) {
        arr[board[n][i]] = 1;
        for (int j = 0; j < idx_size[board[n][i]]; j++) {
            check[idx[board[n][i]][j]] = 1;
            dfs(idx[board[n][i]][j]);
        }
    }
}

int main() {
    int n, m, p;
    scanf("%d %d\n %d", &n, &m, &p);
    for (int i = 0; i < p; i++) {
        int tmp;
        scanf("%d", &tmp);
        arr[tmp] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &size[i]);
        for (int j = 0; j < size[i]; j++) {
            int tmp;
            scanf("%d", &board[i][j]);
            idx[board[i][j]][idx_size[board[i][j]]] = i;
            idx_size[board[i][j]]++;
            if (arr[board[i][j]] == 1) {
                check[i] = 1;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (check[i] == 1) {
            dfs(i);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (check[i]) continue;
        ans++;
    }

    printf("%d", ans);
}