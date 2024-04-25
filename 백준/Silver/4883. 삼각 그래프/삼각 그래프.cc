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
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
using namespace std;
int N;
int dp[3][100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int i = 1;
    while (1) {
        cin >> N;
        if (N == 0) break;
        int x, y, z;
        cin >> x >> y >> z;
        dp[0][1] = 1000001;
        dp[1][1] = y;
        dp[2][1] = y + z;
        for (int i = 2; i <= N; i++) {
            cin >> x >> y >> z;
            dp[0][i] = min(dp[0][i - 1], dp[1][i - 1]) + x;
            dp[1][i] = min({dp[0][i - 1], dp[1][i - 1], dp[2][i - 1], dp[0][i]}) + y;
            dp[2][i] = min(dp[2][i - 1], min(dp[1][i - 1], dp[1][i])) + z;
        }
        cout << i << ". " << dp[1][N] << "\n";
        fill(dp[0], dp[0] + N + 1, 0);
        fill(dp[1], dp[1] + N + 1, 0);
        fill(dp[2], dp[2] + N + 1, 0);
        i++;
    }

    return 0;
}