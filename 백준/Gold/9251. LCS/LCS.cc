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

int dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string N, M;

    cin >> N >> M;
    int n_size = N.size();
    int m_size = M.size();

    for (int i = 1; i <= n_size; i++) {
        for (int j = 1; j <= m_size; j++) {
            if (N[i - 1] == M[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n_size][m_size];
    

    return 0;
}