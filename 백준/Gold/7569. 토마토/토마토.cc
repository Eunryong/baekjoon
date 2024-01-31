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

int M, N, H;
int vis[101][101][101];
int arr[101][101][101];
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N >> H;
    queue<pair<int, pair<int, int> > > q;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> arr[i][j][k];
                if (arr[i][j][k] == 1) 
                    q.push(make_pair(i, make_pair(j, k)));
            }
        }
    }
    int ans = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second.first;
        int z = q.front().second.second;
        q.pop();
        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if (nx >= 0 && nx < H && ny >= 0 && ny < N && nz >= 0 && nz < M && arr[nx][ny][nz] == 0) {
                q.push(make_pair(nx, make_pair(ny, nz)));
                arr[nx][ny][nz] = arr[x][y][z] + 1;
            }
        }
    }
    int max = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (max < arr[i][j][k])
                    max = arr[i][j][k];
                if (arr[i][j][k] == 0) {
                    cout << "-1";
                    return 0;
                }
            }
        }
    }
    cout << max - 1;
    return 0;
}