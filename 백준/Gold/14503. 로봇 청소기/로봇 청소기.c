#include <stdio.h>
#include <memory.h>
int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    int dir, x, y;
    scanf("%d %d %d", &x, &y, &dir);
    int arr[r][c];
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int size = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    while (1) {
        if (arr[x][y] == 0) {
            size++;
            arr[x][y] = -1;
        } else {
            int n_size = 0;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (arr[nx][ny] == 0) n_size++;
            }

            if (n_size == 0) {
                int nx = x - dx[dir];
                int ny = y - dy[dir];
                if (arr[nx][ny] == 1) {
                    break;
                } else {
                    x = nx;
                    y = ny;
                }
            } else {
                for (int i = 0; i < 4; i++) {
                    dir += 3;
                    dir %= 4;
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (arr[nx][ny] == 0){
                        x = nx;
                        y = ny;
                        break;
                    }
                }
            }
        }
    }
    printf("%d", size);
}