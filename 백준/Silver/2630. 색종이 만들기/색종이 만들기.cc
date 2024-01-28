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
int arr[128][128];
int ans[2];
void solve(int x, int y, int n) {
    int result = 0;
    int tmp = arr[x][y];
    if (n == 1) {
        ans[tmp]++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (result) break ;
        for (int j = 0; j < n; j++) {
            if (result) break ;
            if (tmp != arr[i + x][j + y])
               result = 1;
        }
    }
    if (result) {
        solve(x, y, n / 2);
        solve(x + n / 2, y + n / 2, n / 2);
        solve(x, y + n / 2, n / 2);
        solve(x + n / 2, y, n / 2);
    } else {
        ans[tmp]++;
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
        }
    }
    solve(0, 0, N);
    cout << ans[0] << "\n" << ans[1];
    return 0;
}