#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <cmath>
using namespace std;
int N, M;
char arr[11][11];
int r_x, r_y, b_x, b_y;
int ans = 11;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1 ,0, -1, 0};

void move_end(int dir, int x, int y, char rb) {
    while (1) {
        if (arr[x][y] == 'O') break;
        if (arr[x + dx[dir]][y + dy[dir]] == '#')
            break;
        if (rb == 'R' && (x + dx[dir] == b_x && y + dy[dir] == b_y) && arr[b_x][b_y] != 'O') {
            break;
        }
        if (rb == 'B' && (x + dx[dir] == r_x && y + dy[dir] == r_y) && arr[r_x][r_y] != 'O') {
            break;
        }
        x += dx[dir];
        y += dy[dir];
    }

    if (rb == 'R') {
        r_x = x; r_y = y;
    }
    if (rb == 'B') {
        b_x = x; b_y = y;
    }
}

void move(int dir, int rx, int ry, int bx, int by, int cnt) {
    r_x = rx; r_y = ry; b_x = bx; b_y = by;
    move_end(dir, r_x, r_y, 'R');
    move_end(dir, b_x, b_y, 'B');
    move_end(dir, r_x, r_y, 'R');
    move_end(dir, b_x, b_y, 'B');
    
    if (arr[r_x][r_y] == 'O' && arr[b_x][b_y] != 'O') {
        ans = min(ans, cnt + 1);
    }
}

void dfs(int rx, int ry, int bx, int by, int cnt) {
    if (cnt > 10) return;
    move(0, rx, ry, bx, by, cnt);
    dfs(r_x, r_y, b_x, b_y, cnt + 1);
    move(1, rx, ry, bx, by, cnt);
    dfs(r_x, r_y, b_x, b_y, cnt + 1);
    move(2, rx, ry, bx, by, cnt);
    dfs(r_x, r_y, b_x, b_y, cnt + 1);
    move(3, rx, ry, bx, by, cnt);
    dfs(r_x, r_y, b_x, b_y, cnt + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    int rx, ry, bx, by;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'R') {
                arr[i][j] = '.';
                rx = i;
                ry = j;
            }
            if (arr[i][j] == 'B') {
                arr[i][j] = '.';
                bx = i;
                by = j;
            }
        }
    }
    dfs(rx, ry, bx, by, 0);
    if (ans == 11) cout << -1;
    else cout << ans;
    return 0;
}