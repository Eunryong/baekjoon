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
int n, m, k;
string arr[51];
int ans = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> k;
    for (int i = 0; i < n; i++) {
        int zero_cnt = 0;
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '0') zero_cnt++;
        }
        int sum = 0;
        if (zero_cnt <= k && zero_cnt % 2 == k % 2) {
            for (int j = 0; j < n; j++) {
                if (arr[i] == arr[j]) sum++;
            }
        }
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}