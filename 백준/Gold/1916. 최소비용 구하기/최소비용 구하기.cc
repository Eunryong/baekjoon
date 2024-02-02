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
int N, M;
bool vis[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    vector<pair <int, int> > v[1001];
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    for (int i = 1; i <= M; i++) {
        int s, e, d;
        cin >> s >> e >> d;
        v[s].push_back(make_pair(d, e));
    }
    int st, en;
    cin >> st >> en;
    int ans = 2147483647;
    q.push(make_pair(0, st));
    while (!q.empty()) {
        int dis = q.top().first;
        int idx = q.top().second;
        q.pop();
        if (idx == en) {
            cout << dis;
            return 0;
        }
        if (vis[idx]) continue;
        vis[idx] = 1;
        for (int i = 0; i < v[idx].size(); i++) {
            if(!vis[v[idx][i].second]) {
                q.push(make_pair(dis + v[idx][i].first, v[idx][i].second));
            }
        }
        
    }

    return 0;
}