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
#include <memory.h>

using namespace std;
#define infinity 1000000000
vector<pair<int, int> > graph[1001];
int n, m;
int prev_node[1001];
int dist[1001];

struct compare {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if (a.second != b.second) return a.second < b.second;
        else return a.first < b.first;
    }
};

void dijkstra(int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;
    fill_n(dist, n + 1, infinity);
    dist[start] = 0;
    pq.push({start, 0});
    while (!pq.empty()) {
        int now = pq.top().first;
        int now_dist = pq.top().second;
        pq.pop();
        if (dist[now] < now_dist) continue;
        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;
            int next_dist = graph[now][i].second + now_dist;

            if (next_dist < dist[next]) {
                prev_node[next] = now;
                dist[next] = next_dist;
                pq.push({next, next_dist});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int st, en, ex;
        cin >> st >> en >> ex;
        graph[st].push_back({en, ex});
    }
    int st, en;
    cin >> st >> en;
    dijkstra(st, en);
    cout << dist[en] << "\n";
    int cnt = 1;
    stack<int> node;
    for (int i = en; i != 0; i = prev_node[i]) {
        node.push(i);
        cnt++;
    }
    cout << node.size() << "\n";
    while (!node.empty()) {
        cout << node.top() << " ";
        node.pop();
    }
    return 0;
}