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
int N, M, H;
int arr[31][11];
int ans = 4;

int line(int x, int y) {
    for (int i = x; i <= H; i++) {
        if (arr[i][y])
            y = arr[i][y];
    }
    return y;
}

bool end_game() {
    for (int i = 1; i <= N; i++) {
        if (i != line(1, i)) return false;
    }
    return true;
}

void dfs(int x, int y, int cnt) {
    if (cnt >= 3 || x > H) return;
    if (y >= N) {dfs(x + 1, 1, cnt); return;}
    if (arr[x][y + 1] == 0 && arr[x][y - 1] != y && arr[x][y] == 0) {
        arr[x][y] = y + 1;
        arr[x][y + 1] = y;
        if (end_game()) {
            ans = min(ans, cnt + 1);
            arr[x][y] = 0;
            arr[x][y + 1] = 0;
            return ;
        }
        dfs(x, y + 2, cnt + 1);
        arr[x][y] = 0;
        arr[x][y + 1] = 0;
    }
    dfs(x, y + 1, cnt);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> H;
    for (int i = 0; i <= H; i++) {
        fill(arr[i], arr[i] + N + 1, 0);
    }
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = y + 1;
        arr[x][y + 1] = y;
    }
    if (end_game()) {
        cout << 0;
        return 0;
    }
    dfs(1, 1, 0);
    if (ans < 4) cout << ans;
    else cout << -1;
    return 0;
}