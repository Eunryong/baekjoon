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
int arr[1001][1001];
int dp[1001][1001];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    queue<pair<int, int> > q;
    for (int i = 1; i <= N; i++) {
        fill_n(dp[i], M + 1, -1); 
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                q.push(make_pair(i, j));
                dp[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x < 0 || x > N || y < 0 || y > M) continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx > 0 && nx <= N && ny > 0 && ny <= M && dp[nx][ny] == -1 && arr[nx][ny] == 1) {
                dp[nx][ny] = dp[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (arr[i][j] == 0) {
                cout << arr[i][j] << " ";
            } else
                cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}