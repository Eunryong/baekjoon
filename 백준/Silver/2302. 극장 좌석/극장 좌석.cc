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
int dp[41];
bool vip[41];
int N, M;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int x;
        cin >> x;
        vip[x] = 1;
    }
    int j = 0;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int ans = 1;
    for (int i = 1; i <= N + 1; i++) {
        if (vip[i] || i == N + 1) {
            ans *= dp[j];
            j = 0;
        } else {
            j++;
        }
    }
    cout << ans;
    return 0;
}