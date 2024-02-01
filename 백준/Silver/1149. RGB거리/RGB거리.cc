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
int sum[1000001];
int dp[1000][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> v[3];
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 3; k++) {
                int tmp;
                cin >> tmp;
                v[k].push_back(tmp);
            }
        }
    }
    dp[0][0] = v[0][0];
    dp[0][1] = v[1][0];
    dp[0][2] = v[2][0];

    for (int i = 1; i < N; i++) {
        dp[i][0] = min(dp[i - 1][1] + v[0][i], dp[i - 1][2] + v[0][i]);
        dp[i][1] = min(dp[i - 1][0] + v[1][i], dp[i - 1][2] + v[1][i]);
        dp[i][2] = min(dp[i - 1][0] + v[2][i], dp[i - 1][1] + v[2][i]);
    }
    cout << min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));

    return 0;
}