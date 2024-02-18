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
int L, R, C;
char arr[31][31][31];
int vis[31][31][31];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (1) {
        cin >> L >> R >> C;
        queue<tuple<int, int , int> > q;
        int ex, ey, ez;
        if (!L && !R && !C) return 0;
        for (int i = 1; i <= L; i++) {
            for (int j = 1; j <= R; j++) {
                for (int k = 1; k <= C; k++) {
                    cin >> arr[i][j][k];
                    if (arr[i][j][k] == 'S') {
                        q.push(make_tuple(i, j, k));
                    } else if ( arr[i][j][k] == 'E') {
                        ex = i; ey = j; ez = k;
                    }
                }
                fill(vis[i][j], vis[i][j] + C + 1, 0);
            }
        }
        while (!q.empty()) {
            int x = get<0>(q.front());
            int y = get<1>(q.front());
            int z = get<2>(q.front());
            q.pop();
            if (arr[x][y][z] == 'E') {
                break ;
            }
            for (int i = 0; i < 6; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nz = z + dz[i];
                if (nx > 0 && nx <= L && ny > 0 &&  ny <= R && nz > 0 && nz <= C && arr[nx][ny][nz] != '#' && !vis[nx][ny][nz]) {
                    q.push({nx,ny,nz});
                    vis[nx][ny][nz] = vis[x][y][z] + 1;
                }
            }
        }
        if (vis[ex][ey][ez]) {
            cout << "Escaped in " << vis[ex][ey][ez] << " minute(s).\n";
        } else {
            cout << "Trapped!\n";
        }
    }
    return 0;
}