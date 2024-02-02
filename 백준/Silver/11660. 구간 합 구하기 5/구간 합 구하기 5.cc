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
int dp[1025][1025];
int N, M;
int arr[1025][1025];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    int x1, x2, y1, y2;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                int tmp;
                cin >> tmp;
                dp[i][j] = dp[i][j - 1] + tmp;
            }
        }
    for (int i = 1; i <= M; i++) {
        
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = 0;
        for (int j = x1; j <= x2; j++) {
            sum += dp[j][y2] - dp[j][y1 - 1];
        }
        cout << sum << "\n";
    }
    return 0;
}