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

int N, dp[301][3];
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    dp[1][1] = v[0];
    dp[1][2] = 0;
    dp[2][1] = v[1];
    dp[2][2] = v[1] + v[0];
    for (int i = 3; i <= N; i++) {
        dp[i][1] = max(dp[i - 2][2], dp[i - 2][1]) + v[i - 1];
        dp[i][2] = dp[i - 1][1] + v[i - 1];
    }
    cout << max(dp[N][1], dp[N][2]);

    return 0;
}