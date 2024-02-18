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
int R, C;
char arr[51][51];
int vis[51][51];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    int e_x, e_y;
    queue<pair<int, int> > q;
    queue<pair<int, int> > w;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'S') {
                q.push({i, j});
            } else if (arr[i][j] == '*') {
                w.push({i, j});
            }
        }
    }
    int ans = 0;
    while (!q.empty() && !ans) {
        int size = w.size();
        while (size--) {
            int x = w.front().first;
            int y = w.front().second;
            w.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx > 0 && nx <= R && ny > 0 && ny <= C && arr[nx][ny] != 'D' && arr[nx][ny] != 'X' && arr[nx][ny] != '*') {
                    arr[nx][ny] = '*';
                    w.push({nx, ny});
                }
            }
        }
        size = q.size();
        while (size--) {
            int x = q.front().first;
            int y = q.front().second;
            if (arr[x][y] == 'D') {
                ans = vis[x][y];
                break;
            }
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx > 0 && nx <= R && ny > 0 && ny <= C && arr[nx][ny] != '*' && arr[nx][ny] != 'X' && !vis[nx][ny]) {
                    vis[nx][ny] = vis[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    if (ans) cout << ans;
    else cout << "KAKTUS";
    return 0;
}