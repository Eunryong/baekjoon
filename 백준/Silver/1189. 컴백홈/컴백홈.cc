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
int R, C, K;
int ans, cnt = 1;
bool vis[5][5];
char arr[5][5];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void dfs(int x, int y) {
    if (x == 0 && y == C - 1) {
        if (cnt == K) ans++;
        return ;
    }
    for (int i = 0; i < 4; i++) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (nx >= 0 && ny >= 0 && nx < R && ny < C && arr[nx][ny] != 'T' && !vis[nx][ny]) {
            vis[nx][ny] = 1;
            cnt++;
            dfs(nx, ny);
            vis[nx][ny] = 0;
            cnt--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C >> K;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }
    vis[R - 1][0] = 1;
    dfs(R - 1, 0);
    cout << ans;
    return 0;
}