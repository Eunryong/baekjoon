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
int n, k;
int arr[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (k > i) {
            sum += arr[i];
        }
    }
    int ans = sum;
    for (int i = 1; i + k - 1 < n; i++) {
        sum -= arr[i - 1] - arr[i + k - 1];
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}