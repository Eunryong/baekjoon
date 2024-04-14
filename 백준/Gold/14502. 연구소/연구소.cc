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
int N, M, cnt;
int arr[9][9], tmp[9][9];
bool vis[9][9];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int ans;

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > N || ny < 1 || ny > M || tmp[nx][ny] != 0) 
            continue;
        tmp[nx][ny] = 3;
        dfs(nx, ny);
    }
}

void solve() {
    int zero = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            vis[i][j] = 0;
            tmp[i][j] = arr[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (!vis[i][j] && tmp[i][j] == 2) {
                dfs(i, j);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (tmp[i][j] == 0) zero++;
        }
    }
    ans = max(ans, zero);
}

void make_wall(int x, int y, int cnt) {
    if (y > M) {make_wall(x + 1, y - M, cnt); return;}
    if (x > N && cnt == 3) {solve(); return;}
    else if (x > N) {
        return;
    }
    if (arr[x][y] == 0 && cnt < 3) {
        arr[x][y] = 1;
        make_wall(x, y + 1, cnt + 1);
        arr[x][y] = 0;
    }
    make_wall(x, y + 1, cnt);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    make_wall(1, 1, 0);
    cout << ans;
    
    return 0;
}