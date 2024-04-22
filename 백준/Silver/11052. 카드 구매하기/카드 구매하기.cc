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
int N, P[10001];
int dp[10001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }
    dp[1] = P[1];
    for (int i = 2; i <= N; i++) {
        dp[i] = P[i];
        for (int j = 1; j <= i / 2; j++) {
            dp[i] = max(dp[i], dp[j] + dp[i - j]);
        }
    }
    cout << dp[N];
    return 0;
}