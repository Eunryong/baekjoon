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
char arr[21][21];
bool vis[21][21];
bool c[26];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ans;
void dfs(int x, int y, int cnt) {
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx > 0 && ny > 0 && nx <= R && ny <= C && !vis[nx][ny] && !c[arr[nx][ny] - 'A']) {
            vis[nx][ny] = 1;
            c[arr[nx][ny] - 'A'] = 1;
            dfs(nx, ny, cnt + 1);
            vis[nx][ny] = 0;
            c[arr[nx][ny] - 'A'] = 0;
        }
    }
    ans = max(ans, cnt);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> arr[i][j]; 
        }
    }
    vis[1][1] = 1;
    c[arr[1][1] - 'A'] = 1;
    dfs(1, 1, 1);
    cout  << ans;
    return 0;
}