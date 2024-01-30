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
char arr[27][27];
int vis[27][27];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int> > q;

int bfs(int i, int j) {
    q.push(make_pair(i, j));
    int size = 1;
    vis[i][j] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx > 0 && nx <= N && ny > 0 && ny <= N && !vis[nx][ny] && arr[nx][ny] == '1') {
                size++;
                vis[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    return (size);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    vector<int> v;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!vis[i][j] && arr[i][j] == '1') {
                v.push_back(bfs(i, j));
                ans++;
            }
        }
    }
    sort(v.begin(), v.end());
    cout << ans << "\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }
    
    return 0;
}