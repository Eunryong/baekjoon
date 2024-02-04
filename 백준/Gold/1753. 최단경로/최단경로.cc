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

int V, E;
int st;
int dis[20001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> V >> E;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    vector<pair<int, int> > v[20001];
    cin >> st;
    for (int i = 0; i < E; i++) {
        int s, en, dis;
        cin >> s >> en >> dis;
        v[s].push_back({en, dis});
    }
    fill(dis, dis + 20001, -1);
    q.push({0, st});
    while (!q.empty()) {
        int x = q.top().second;
        int d = q.top().first;
        q.pop();
        if (dis[x] != -1) continue;
        dis[x] = d;
        for (int i = 0; i < v[x].size(); i++) {
            int nx = v[x][i].first;
            if (dis[nx] == -1) {
                q.push({d + v[x][i].second, nx});
            }
        }
    }
    for (int i = 1; i <= V; i++) {
        if (dis[i] == -1) cout << "INF\n";
        else cout << dis[i] << "\n";
    }
    return 0;
}