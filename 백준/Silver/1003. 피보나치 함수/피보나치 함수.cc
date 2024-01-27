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
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
using namespace std;

int N, T;
int dp[41];

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = fib(n - 1) + fib(n - 2);
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    fill_n(dp, 41, -1);
    for (int i = 0; i < T; i++) {
        cin >> N;
        if (N == 0) {
            cout << "1 0\n";
            continue;
        }
        cout << fib(N - 1) << " " << fib(N) << "\n";
    }
    return 0;
}