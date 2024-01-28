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
int arr[501][501];
int dx[8] = {-1, 1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1,-1, 1, -1, 1};
int ans;
bool visit[501][501];
void solve(int x, int y, int n, int sum) {
    visit[x][y] = 1;
    if (n == 4) {
        ans = max(sum, ans);
        return;
    }
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (i < 4 && nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if (!visit[nx][ny]) {
                solve(nx, ny, n + 1, sum + arr[nx][ny]);
                visit[nx][ny] = 0;
            }
        }
        if (i > 3 && nx >= 0 && nx < N && ny >= 0 && ny < M) {
            for (int j = 0; j < 4; j++) {
                int nx2 = nx + dx[j];
                int ny2 = ny + dy[j];
                if (nx2 >= 0 && nx2 < N && ny2 >= 0 && ny2 < M && visit[nx2][ny2] && !visit[nx][ny]) {
                    solve(nx, ny, n + 1, sum + arr[nx][ny]);
                    visit[nx][ny] = 0;
                }
            }
        }
    }
    visit[x][y] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    int max = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            solve(i, j, 1, arr[i][j]);
        }
    }
    cout << ans;
    return 0;
}