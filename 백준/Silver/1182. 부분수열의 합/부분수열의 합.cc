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
#include <set>
using namespace std;

int N, S;
int ans;
vector<int> v;

void solve(int idx, int sum) {
    if (idx == N) {
        if (sum == S)
            ans++;
        return ;
    }
    solve(idx + 1, sum);
    solve(idx + 1, sum + v[idx]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    solve(0, 0);
    if (S == 0)
        ans--;
    cout << ans;

    return 0;
}