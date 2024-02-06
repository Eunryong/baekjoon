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
char arr[1001][1001];
int d[1001][1001];
int d2[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    queue<tuple<int, int, bool> > q;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
        fill(d[i], d[i] + M + 1, -1);
        fill(d2[i], d2[i] + M + 1, -1);
    }

    q.push({1, 1, false});
    d[1][1] = 1;
    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        bool c = get<2>(q.front());
        q.pop();
        if (x == N && y == M) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx > 0 && nx <= N && ny > 0 && ny <= M && arr[nx][ny] == '0' && d[nx][ny] == -1&& c == false) {
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny, c});
            } else if (nx > 0 && nx <= N && ny > 0 && ny <= M && arr[nx][ny] == '0' && d2[nx][ny] == -1 && c == true) {
                d2[nx][ny] = d2[x][y] + 1;
                q.push({nx, ny, c});
            }
            if (nx > 0 && nx <= N && ny > 0 && ny <= M && arr[nx][ny] == '1' && d2[nx][ny] == -1 && c == false) {
                d2[nx][ny] = d[x][y] + 1;
                q.push({nx, ny, true});
            }
        }
    }
    if (d[N][M] == -1 && d2[N][M] == -1)
        cout << -1;
    else if (d[N][M] == -1 || d2[N][M] == -1)
        cout << max(d[N][M], d2[N][M]);
    else
        cout << min(d[N][M], d2[N][M]);
    return 0;
}