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
int N, M, K;
int arr[101][101];
int vis[101][101];
int ans = 0, n;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
void dfs(int x, int y) {
    vis[x][y] = 1;
    n++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx > 0 && nx <= N && ny > 0 && ny <= M && !vis[nx][ny] && arr[nx][ny] == 1)
            dfs(nx, ny);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    queue<pair<int, int> > q;
    for (int i = 1; i <= K; i++) {
        int r, c;
        cin >> r >> c;
        arr[r][c] = 1;
        q.push({r, c});
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (!vis[x][y]) {
            n = 0;
            dfs(x, y);
            ans = max(ans, n);
        }
    }
    cout << ans;

    return 0;
}