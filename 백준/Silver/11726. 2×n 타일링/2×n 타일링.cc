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
int dp[1001];
int solve(int n) {
    if (n <= 0) return 0;
    if (dp[n]) return dp[n];
    int result = solve(n - 1) % 10007 + solve(n - 2) % 10007;
    dp[n] = result;
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    dp[1] = 1;
    dp[2] = 2;
    cout << solve(N) % 10007;
    return 0;
}