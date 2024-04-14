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

int arr[101], N, o[4];
int min_ans = 1000000001, max_ans = -1000000001;

void solve(int idx, int ans) {
    if (idx == N) {
        min_ans = min(min_ans, ans);
        max_ans = max(max_ans, ans);
        return ;
    }
    if (o[0] > 0) {
        o[0]--;
        solve(idx + 1, ans + arr[idx]);
        o[0]++;
    }
    if (o[1] > 0) {
        o[1]--;
        solve(idx + 1, ans - arr[idx]);
        o[1]++;
    }
    if (o[2] > 0) {
        o[2]--;
        solve(idx + 1, ans * arr[idx]);
        o[2]++;
    }
    if (o[3] > 0) {
        o[3]--;
        solve(idx + 1, ans / arr[idx]);
        o[3]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> o[i];
    }
    solve(1, arr[0]);
    cout << max_ans << "\n" << min_ans;
    return 0;
}