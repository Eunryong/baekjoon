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
bool vis[501];
int ans;
vector<int> v[501];
bool dfs(int n, int before) {
    vis[n] = 1;
    
    for (int i = 0; i < v[n].size(); i++) {
        if (v[n][i] == before) continue;
        if (vis[v[n][i]]) return false;
        if (!dfs(v[n][i], n)) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int c = 1;
    while (1) {
        int N, M;
        cin >> N >> M;
        fill(vis, vis + 501, 0);
        if (N == 0 && M == 0) {
            return 0;
        }
        ans = 0;
        for (int i = 0; i < M; i++) {
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        for (int i = 1; i <= N; i++) {
            if (!vis[i]) {
                if (dfs(i, 0)) {
                    ans++;
                }
            }
        }
        if (!ans)
            cout << "Case " << c << ": No trees.\n";
        else if (ans > 1) {
            cout << "Case " << c << ": A forest of " << ans <<" trees.\n";
        } else {
            cout << "Case " << c << ": There is one tree.\n";
        }
        for (int i = 1; i <= N; i++) {
            v[i].clear();
        }
        c++;
    }
    return 0;
}