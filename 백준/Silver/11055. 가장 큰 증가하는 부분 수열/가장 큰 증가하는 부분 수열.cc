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

long long dp[1001][1001];
int arr[1001];
int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];

    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 1000; j++) {
            if (j != arr[i])
                dp[i][j] = dp[i - 1][j];
            if (j < arr[i])
                dp[i][arr[i]] = max(dp[i][arr[i]], dp[i - 1][j] + arr[i]);
        }
    }
    cout << *max_element(dp[N], dp[N] + 1001);
    return 0;
}