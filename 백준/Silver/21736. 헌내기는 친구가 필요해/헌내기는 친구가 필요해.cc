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
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
bool vis[601][601];
char arr[601][601];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    queue<pair<int, int> > q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'I') {
                q.push(make_pair(i, j));
            }
        }
    }
    int ans = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (vis[x][y]) continue;
        if (arr[x][y] == 'P') ans++;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !vis[nx][ny] && arr[nx][ny] != 'X')
                q.push(make_pair(nx, ny));
        }
    }
    if (ans) cout << ans;
    else cout << "TT";

    return 0;
}