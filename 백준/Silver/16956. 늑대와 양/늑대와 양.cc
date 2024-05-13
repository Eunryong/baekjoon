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
int w, h;
char arr[501][501];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> w >> h;
    bool c = 0;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (arr[i][j] == 'W') {
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= w || nx < 0 || ny >= h || ny < 0) continue;
                    if (arr[nx][ny] == 'S') {
                        cout << 0;
                        return 0;
                    }
                    if (arr[nx][ny] == '.') {
                        arr[nx][ny] = 'D';
                    }
                }
            }
        }
    }
    cout << "1\n";
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }
    return 0;
}