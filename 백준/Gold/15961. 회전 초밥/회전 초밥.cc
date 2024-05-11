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
int arr[3001];
queue<int> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> d >> k >> c;
    cnt[c]++;
    int sum = 1;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        arr[i] = x;
        v.push(x);
        if (cnt[x] == 0) sum++;
        cnt[x]++;
    }
    int ans = sum;
    for (int i = 0; i < n; i++) {
        int x;
        if (n - k > i) {
            cin >> x;
        } else {
            x = arr[i - (n - k)];
        }
        cnt[v.front()]--;
        if (cnt[v.front()] == 0) sum--;
        cnt[x]++;
        if (cnt[x] == 1) sum++;
        v.pop();
        v.push(x);
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}