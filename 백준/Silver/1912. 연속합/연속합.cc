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
int arr[100001];
int dp[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    dp[0] = -1000;
    for (int i = 1; i <= N; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    }
    cout << *max_element(dp, dp+N+1);
    return 0;
}