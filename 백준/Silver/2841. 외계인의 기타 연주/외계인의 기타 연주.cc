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
int N, P;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> P;
    stack<int> st[7];
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int p, m;
        cin >> p >> m;
        while (!st[p].empty() && st[p].top() > m) {
            st[p].pop();
            ans++;
        }
        if (!st[p].empty() && st[p].top() == m) {
            continue;
        }
        st[p].push(m);
        ans++;
    }
    cout << ans;
    return 0;
}