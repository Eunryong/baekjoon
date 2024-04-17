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
long long dp[101][10];
long long ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    fill(dp[1] + 1, dp[1] + 10, 1);
    for (int i = 2; i <= N; i++) {    
        for (int j = 0; j < 10; j++) {
            dp[i][j] = ((j > 0 ? dp[i - 1][j - 1] : 0) + (j < 9 ? dp[i - 1][j + 1] : 0)) % 1000000000;
        }
    }
    for (int i = 0; i < 10; i++) {
        ans += dp[N][i] % 1000000000;
        ans %= 1000000000;
    }
    cout << ans;

    return 0;
}