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
int T, N;
long long dp[1000001][4];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 2;
    dp[3][2] = 1;
    dp[3][3] = 1;
    for (int i = 4; i < 1000001; i++) {
        for (int j = 1; j <= 3; j++) {
            dp[i][1] += dp[i - 1][j] % 1000000009;
            dp[i][2] += dp[i - 2][j] % 1000000009;
            dp[i][3] += dp[i - 3][j] % 1000000009;
        }
    }
    while (T--) {
        cin >> N;
        cout << ((dp[N][1] + dp[N][2]) % 1000000009 + dp[N][3]) % 1000000009  << "\n";
    }
    return 0;
}