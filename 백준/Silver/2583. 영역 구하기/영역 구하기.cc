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
int M, N, K;
int vis[101][101];
int arr[101][101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n;
void dfs(int x, int y) {
    n++;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < M && ny >= 0 && ny < N && !vis[nx][ny] && !arr[nx][ny]) {
            dfs(nx, ny);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N >> K;
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 0; i < K; i++) {
        int sx, sy, ex, ey;
        cin >> sy >> sx >> ey >> ex;
        for (int j = sx; j < ex; j++) {
            for (int k = sy; k < ey; k++) {
                arr[j][k] = 1;
            }
        }
    }
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!vis[i][j] && !arr[i][j]) {
                n = 0;
                dfs(i, j);
                q.push(n);
            }
        }
    }
    cout << q.size() << "\n";
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }

    return 0;
}