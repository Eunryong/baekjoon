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
int N, T, G;
int vis[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> T >> G;
    queue<int> q;
    q.push(N);
    int ans = 0;
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        if (n == G) {
            ans = vis[n] + 1;
        }
        if (vis[n] >= T) continue;
        if (n + 1 <= 99999 && !vis[n + 1]) {
            vis[n + 1] = vis[n] + 1;
            q.push(n + 1);
        }
        int size = to_string(n * 2).size();
        int next = n * 2 - pow(10, size - 1);
        if (size <= 5 && next >= 0 && next <= 99999 && !vis[next]) {
            vis[next] = vis[n] + 1;
            q.push(next);
        }
    }
    if (ans) cout << ans - 1;
    else cout << "ANG";
    return 0;
}