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
#include <set>
using namespace std;
int N, arr[1001];
int dp[1001][1001];
int d[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            dp[i][j] = dp[i - 1][j];
            d[i][j] = j;
            if (arr[i] > arr[j]) {
                if (dp[i][i] < dp[i - 1][j] + 1) {
                    dp[i][i] = dp[i - 1][j] + 1;
                    d[i][i] = j;
                }
            }
        }
    }
    int m = 0;
    int idx;
    // cout << *max_element(dp[N], dp[N] + N + 1) << "\n";
    for (int i = 0; i <= N; i++) {
        if (m < dp[N][i]) {
            m = dp[N][i];
            idx = i;
        }
    }
    cout << dp[N][idx] << "\n";
    stack<int> s;
    for (int i = idx; i != 0; i = d[i][i]) {
        s.push(i);
    }
    while (!s.empty()) {
        cout << arr[s.top()] << " ";
        s.pop();
    }

    return 0;
}