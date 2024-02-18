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
int T, I;
char arr[301][301];
int vis[301][301];
int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        int ans = 0;
        queue<pair<int, int> > q;
        cin >> I;
        for (int i = 0; i < I; i++) {
            fill(vis[i], vis[i] + I, 0);
            fill(arr[i], arr[i] + I, 0);
        }
        int x, y;
        cin >> x >> y;
        arr[x][y] = 'S';
        q.push({x, y});
        cin >> x >> y;
        arr[x][y] = 'E';
        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            if (arr[x][y] == 'E') {
                ans = vis[x][y];
                break;
            }
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < I && ny < I && !vis[nx][ny] && arr[nx][ny] != 'S') {
                    vis[nx][ny] = vis[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}