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
int n, d, k, c;
int cnt[3001];
int arr[30001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> d >> k >> c;
    cnt[c]++;
    int sum = 1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i < k) {
            if (cnt[arr[i]] == 0) sum++;
            cnt[arr[i]]++;
        }
    }
    int ans = sum;
    for (int i = 1; i < n; i++) {
        cnt[arr[(i - 1) % n]]--;
        cnt[arr[(i + k - 1) % n]]++;
        sum = 0;
        for (int j = 0; j <= d; j++) {
            if (cnt[j]) {
                sum++;
            }
        }
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}