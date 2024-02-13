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
int n, ans;
int N;
int arr[101][101];
bool vis[101][101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int h;
void dfs(int x, int y) {
    vis[h][x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx > 0 && nx <= N && ny > 0 && ny <= N && !vis[h][nx][ny] && arr[nx][ny] > h) {
            dfs(nx, ny);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int m = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            m = max(arr[i][j], m);
        }
    }
    for (int k = 0; k < m; k++) {
        h = k;
        n = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (arr[i][j] > h && !vis[k][i][j]) {
                    dfs(i, j);
                    n++;
                }
            }
        }
        ans = max(ans, n);
    }
    cout << ans;
    return 0;
}