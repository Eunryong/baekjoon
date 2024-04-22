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
long long dp[1002][11];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= N + 1; i++) {
        int sum = 0;
        for (int j = 0; j < 10; j++) {
            dp[i][j] = (dp[i - 1][j] + sum) % 10007;
            sum += dp[i - 1][j];
        }
        dp[i][10] = sum % 10007;
    }
    cout << dp[N + 1][10];
    return 0;
}
