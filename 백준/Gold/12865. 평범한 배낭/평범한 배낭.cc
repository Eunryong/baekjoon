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
int N, K;
int w[101];
int v[101];
int dp[101][100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];       
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j - w[i] >= 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[N][K];
    return 0;
}