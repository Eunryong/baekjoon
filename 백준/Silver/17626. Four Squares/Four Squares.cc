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
int dp[50001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        int m = 2147483647;
        for (int j = 1; j <= i / j; j++) {
            int tmp = i - j * j;
            m = min(m, dp[tmp]);
        }
        dp[i] = m + 1;
    }
    cout << dp[N];
    return 0;
}