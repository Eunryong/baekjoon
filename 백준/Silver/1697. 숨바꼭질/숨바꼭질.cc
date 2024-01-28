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
int dp[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    queue<int> q;

    fill_n(dp, 100001, -1);
    dp[N] = 0;
    q.push(N);
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        if (tmp < 0 || tmp > 100000) continue;
        if (tmp == K) {cout << dp[tmp]; continue;}
        if (tmp * 2 <= 100000 && dp[2 * tmp] == -1){
            dp[tmp * 2] = dp[tmp] + 1;
            q.push(tmp * 2);
        }
        if (tmp - 1 >= 0 && dp[tmp - 1] == -1){
            dp[tmp - 1] = dp[tmp] + 1;
            q.push(tmp - 1);
        }
        if (tmp + 1 <= 100000 && dp[tmp + 1] == -1) {
            dp[tmp + 1] = dp[tmp] + 1;
            q.push(tmp + 1);
        }
    }
    return 0;
}