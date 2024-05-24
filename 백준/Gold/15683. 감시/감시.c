#include<stdio.h>
int arr[8][8];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int size;
int cc[8][2];
int ans = 64;
int N, M;
#define min(x, y) (x) < (y) ? (x) : (y)
void fill(int x, int y, int dir, int n) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (arr[nx][ny] == 6 || nx < 0 || nx >= N || ny < 0 || ny >= M) return ;
    if (arr[nx][ny] == 0) arr[nx][ny] = n;
    fill(nx, ny, dir, n);
}

void clear(int x, int y, int dir, int n) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (arr[nx][ny] == 6 || nx < 0 || nx >= N || ny < 0 || ny >= M) return ;
    if (arr[nx][ny] == n) arr[nx][ny] = 0;
    clear(nx, ny, dir, n);
}

void dfs(int cnt, int n) {
    if (cnt == size) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] == 0) sum++;
            }
        }
        ans = min(ans, sum);
        return;
    }
    int x = cc[cnt][0];
    int y = cc[cnt][1];
    if (arr[x][y] == 2) {
        for (int i = 0; i < 2; i++) {
            fill(x, y, i, n);
            fill(x, y, i + 2, n);
            dfs(cnt + 1, n + 1);
            clear(x, y, i, n);
            clear(x, y, i + 2, n);
        }
    } else {
        if (arr[x][y] > 2) {
            fill(x, y, 3, n);
        }
        if (arr[x][y] > 3) {
            fill(x, y, 2, n);
        }
        for (int i = 0; i < 4; i++) {
            fill(x, y, i, n);
            dfs(cnt + 1, n + 1);
            if (arr[x][y] == 3) {
                clear(x, y, (i + 3 ) % 4, n);
            } else if (arr[x][y] == 4) {
                clear(x, y, (i + 2) % 4, n);
            } else if (arr[x][y] == 1) {
                clear(x, y, i, n);
            }
        }
        if (arr[x][y] > 2) {
            clear(x, y, 3, n);
        }
        if (arr[x][y] > 3) {
            clear(x, y, 2, n);
        }
    }
}

int main() {
    
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int fill_n = 7;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] > 0 && arr[i][j] < 5) {
                cc[size][0] = i;
                cc[size][1] = j;
                size++;
            } else if (arr[i][j] == 5) {
                for (int k = 0; k < 4; k++) {
                    fill(i, j, k, fill_n);
                }
                fill_n++;
            }
        }
    }
    dfs(0, fill_n);
    printf("%d", ans);
}