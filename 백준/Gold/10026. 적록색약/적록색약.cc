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

int N;
char arr[101][101];
char arr2[101][101];
bool vis[101][101];
bool vis2[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void bfs(int i, int j, int t) {
    queue<pair <int, int> > q;
    q.push(make_pair(i, j));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (t == 0) {
            if(vis[x][y]) continue;
            vis[x][y] = 1;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N && !vis[nx][ny] && arr[x][y] == arr[nx][ny]) {
                    q.push(make_pair(nx, ny));
                }
            }
        } else {
            if(vis2[x][y]) continue;
            vis2[x][y] = 1;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N && !vis2[nx][ny] && arr2[x][y] == arr2[nx][ny]) {
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'R' || arr[i][j] == 'G')
                arr2[i][j] = 'R';
            else
                arr2[i][j] = 'B';
        }
    }
    int ans = 0, ans2 = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!vis[i][j]) {
                bfs(i, j, 0);
                ans++;
            }
            if (!vis2[i][j]) {
                bfs(i, j, 1);
                ans2++;
            }
            
        }
    }
    cout << ans << " " << ans2;
    return 0;
}