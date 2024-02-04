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

int N;
int ans, node;
bool vis[10001];
vector<pair<int, int> >v[10001];
void dfs(int st, int dist) {
    vis[st] = 1;
    if (dist > ans) {
        ans = dist;
        node = st;
    }
    for (int i = 0; i < v[st].size(); i++) {
        pair<int, int> n = v[st][i];
        if (!vis[n.first]) {
            vis[n.first] = 1;
            dfs(n.first, dist + n.second);
            vis[n.first] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i < N; i++) {
        int st, en, d;
        cin >> st >> en >> d;
        v[st].push_back({en, d});
        v[en].push_back({st, d});
    }
    dfs(1, 0);
    fill(vis, vis + 10001, 0);
    dfs(node, 0);
    cout << ans;
    return 0;
}