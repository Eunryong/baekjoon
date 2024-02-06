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

int V;
bool vis[100001];
int node;
int ans = 0;
vector<pair<int, int> > v[100001];

void dfs(int n, int dist) {
    if (dist > ans) {
        node = n;
        ans = dist;
    }
    if (vis[n]) return;
    vis[n] = 1;
    for (int i = 0; i < v[n].size(); i++) {
        if (!vis[v[n][i].first]) {
            // vis[v[n][i].first] = 1;
            dfs(v[n][i].first, dist + v[n][i].second);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> V;
    for (int i = 1; i <= V; i++) {
        int st, en = 0, dist;
        cin >> st;
        while (1) {
            cin >> en;
            if (en == -1) {
                break ;
            }
            cin >> dist;
            v[st].push_back({en, dist});
            v[en].push_back({st, dist});
        }
    }
    dfs(1, 0);
    fill(vis, vis + 100001, 0);
    dfs(node, 0);
    cout << ans;
    return 0;
}