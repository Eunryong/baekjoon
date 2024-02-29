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
int arr[1001][1001];
int sum[1001][1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int R, C, T;
    cin >> R >> C >> T;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> arr[i][j];
            sum[i][j] += (j != 0 ? sum[i][j - 1] : 0) + arr[i][j];
        }
    }
    int r1, r2, c1, c2;
    while(T--) {
        cin >> r1 >> c1 >> r2 >> c2;
        int ans = 0;
        for (int i = r1; i <= r2; i++) {
            ans += sum[i][c2] - sum[i][c1 - 1];
        }
        cout << ans / ((r2 + 1 - r1) * (c2 + 1 - c1)) << "\n";
    }
    return 0;
}