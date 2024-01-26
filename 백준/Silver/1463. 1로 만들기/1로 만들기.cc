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
int dp[1000001];
int solve(int i) {
    if (i == 1) return 0;
    if (dp[i] != -1) return dp[i];
    int ans = solve(i - 1) + 1;
    if (i % 3 == 0) {
        ans = min(ans, solve(i / 3) + 1);
    }
    if (i % 2 == 0) {
        ans = min(ans, solve(i / 2) + 1);
    }
    dp[i] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    fill_n(dp, 1000001, -1);
    
    cout << solve(N);
    return 0;
}