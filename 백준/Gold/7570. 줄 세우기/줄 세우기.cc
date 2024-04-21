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
int N, arr[1000001], dp[1000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        arr[x] = i;
    }
    fill(dp + 1, dp + N + 1, 1);
    for (int i = 1; i <= N; i++) {
        // cout << arr[i] << " ";
        if (arr[i] > arr[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        }
    }
    cout << N - *max_element(dp + 1, dp + N + 1);
    return 0;
}