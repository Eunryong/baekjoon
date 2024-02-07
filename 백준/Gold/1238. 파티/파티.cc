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

int N, M, X;
int d[2][1001][1001];
int dist[2][1001];
int res[1001];
int ans;

void solve(int f) {
    fill(dist[f], dist[f] + N + 1, 1e9+7);
    dist[f][X] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, X});

    while (!pq.empty()) {
        int dis = pq.top().first;
        int n = pq.top().second;
        pq.pop();

        if (dis > dist[f][n]) continue;

        for (int i = 1; i <= N; i++) {
            if (d[f][n][i]) {
                if (dis + d[f][n][i] < dist[f][i]) {
                    dist[f][i] = dis + d[f][n][i];
                    pq.push({dis + d[f][n][i], i});
                }
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> X;
    for (int i = 1; i <= M; i++) {
        int st, en, dis;
        cin >> st >> en >> dis;
        d[0][st][en] = dis;
        d[1][en][st] = dis;
    }
    solve(1);
    solve(0);
    for (int i = 1; i<= N; i++) {
        ans = max(ans, dist[0][i] + dist[1][i]);
    }
    cout << ans;
    return 0;
}