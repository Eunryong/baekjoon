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
int T, W, H;
char arr[1001][1001];
int vis[1001][1001];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        queue<pair<int, int> > f;
        queue<pair<int, int> > q;
        cin >> W >> H;
        int ans = 0;
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == '@') {
                    q.push({i, j});
                } else if (arr[i][j] == '*') {
                    f.push({i, j});
                }
            }
            fill(vis[i], vis[i] + W + 1, 0);
        }
        while (!q.empty() && !ans) {
            int x, y;
            int size = f.size();
            while (size--) {
                x = f.front().first;
                y = f.front().second;
                f.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx > 0 && nx <= H && ny > 0 && ny <= W && arr[nx][ny] != '#' && arr[nx][ny] != '*') {
                        arr[nx][ny] = '*';
                        f.push({nx, ny});
                    }
                }
            }
            size = q.size();
            while (size-- && !ans) {
                x = q.front().first;
                y = q.front().second;
                q.pop();
                if (x == 1 || y == 1 || x == H || y == W) {
                    ans = vis[x][y] + 1;
                    break ;
                }
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx > 0 && nx <= H && ny > 0 && ny <= W && arr[nx][ny] == '.' && !vis[nx][ny]) {
                        vis[nx][ny] = vis[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        if (ans) cout << ans << "\n";
        else cout << "IMPOSSIBLE\n";
    }

    return 0;
}