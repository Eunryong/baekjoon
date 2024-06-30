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
int dist[501];
int n, m ,w;
#define inf 1000000000
bool bellman_ford( vector<tuple<int, int, int> > graph) {
    dist[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < graph.size(); j++) {
            int from = get<0>(graph[j]);
            int to = get<1>(graph[j]);
            int cost = get<2>(graph[j]);
            if (dist[to] > dist[from] + cost) dist[to] = dist[from] + cost;
        }
    }
    for (int i = 0; i < graph.size(); i++) {
        int from = get<0>(graph[i]);
        int to = get<1>(graph[i]);
        int cost = get<2>(graph[i]);
        if (dist[to] > dist[from] + cost) {
            return 1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> w;
        vector<tuple<int, int, int> > graph;
        fill_n(dist, n + 1, inf);
        for (int i = 0; i < m; i++) {
            int st, en, co;
            cin >> st >> en >> co;
            graph.push_back({st, en, co});
            graph.push_back({en, st, co});
        }
        for (int i = 0; i < w; i++) {
            int st, en, co;
            cin >> st >> en >> co;
            graph.push_back({st, en, -co});
        }
        if (bellman_ford(graph)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}