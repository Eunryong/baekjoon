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
#include <cstring>
using namespace std;
int N, W[16][16], dp[16][1 << 16];

int solve(int c, int vis) {
    int &ret = dp[c][vis];
    if (ret != -1) return ret;
    if (vis == (1 << N) - 1) {
        if (W[c][0] != 0) return W[c][0];
        return 100000000;
    }

    ret = 100000000;
    for (int i = 0; i < N; i++) {
        if (vis & (1 << i) || W[c][i] == 0) continue;
        ret = min(ret, solve(i, vis | (1 << i)) + W[c][i]);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> W[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    int ans = solve(0, 1);
    cout << ans;
    return 0;
}