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
int arr[10][10];
int ans = 26, cnt;
int c[6];

bool check(int x, int y, int n) {
    if (10 - x < n || 10 - y < n) {
        return false;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[x + i][y + j] == 0) return false;
        }
    }
    return true;
}

void dfs(int x, int y) {
    if (y > 9) {
        dfs(x + 1, y - 10);
        return;
    }
    if (x > 9) {
        ans = min(ans, cnt);
        return ;
    }
    if (arr[x][y] == 1) {
        for (int i = 5; i > 0; i--) {
            if (check(x, y, i) && c[i] < 5) {
                for (int j = 0; j < i; j++) {
                    fill(arr[x + j] + y, arr[x + j] + y + i, 0);
                }
                c[i]++;
                cnt++;
                dfs(x, y + 1);
                for (int j = 0; j < i; j++) {
                    fill(arr[x + j] + y, arr[x + j] + y + i, 1);
                }
                c[i]--;
                cnt--;
            }
        }
    } else {
        dfs(x, y + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> arr[i][j];
        }
    }
    dfs(0, 0);
    if (ans != 26) cout << ans;
    else cout << -1;
    return 0;
}