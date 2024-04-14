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
int N, arr[21][21];
vector<int> v;
vector<int> v2;
int ans = 1000000000;

void solve(int idx, int a_sum, int b_sum) {
    if (idx == N + 1 && v.size() == N / 2 && v2.size() == N / 2) {
        ans = min(ans, abs(a_sum - b_sum));
        return;
    }
    if (idx > N) {
        return;
    }
    if (v.size() < N / 2) {
        int sum = 0;
        for (int i = 0; i < v.size(); i++) {
            sum += arr[v[i]][idx];
            sum += arr[idx][v[i]];
        }
        v.push_back(idx);
        solve(idx + 1, a_sum + sum, b_sum);
        v.pop_back();
    }
    if (v2.size() < N / 2) {
        int sum = 0;
        for (int i = 0; i < v2.size(); i++) {
            sum += arr[v2[i]][idx];
            sum += arr[idx][v2[i]];
        }
        v2.push_back(idx);
        solve(idx + 1, a_sum, b_sum + sum);
        v2.pop_back();
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    solve(1, 0, 0);
    cout << ans;
    return 0;
}