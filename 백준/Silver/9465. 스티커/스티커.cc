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
int N, T;
int arr[2][100001];
int dp[2][100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < N; k++) {
                cin >> arr[j][k];
            }
        }
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[0][1] = dp[1][0] + arr[0][1];
        dp[1][1] = dp[0][0] + arr[1][1];
        for (int j = 2; j < N; j++) {
            dp[0][j] = arr[0][j] + max(dp[1][j - 1], dp[1][j - 2]);
            dp[1][j] = arr[1][j] + max(dp[0][j - 1], dp[0][j - 2]);
        }
        cout << max(dp[0][N - 1], dp[1][N - 1]) << "\n";
    }   

    return 0;
}