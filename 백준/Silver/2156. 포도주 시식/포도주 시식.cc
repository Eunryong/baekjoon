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
int dp[10001][3], arr[10001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    dp[1][1] = arr[1];
    for (int i = 2; i <= N; i++) {
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        dp[i][1] = dp[i - 1][0] + arr[i];
        dp[i][2] = dp[i - 1][1] + arr[i];
    }
    cout << max({dp[N][0], dp[N][1], dp[N][2]});
    return 0;
}