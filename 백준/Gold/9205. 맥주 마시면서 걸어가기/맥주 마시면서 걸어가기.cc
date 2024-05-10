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
int T, N;
vector<pair<int, int> > v;
pair<int, int> en;
bool vis[102];
#define mid 32768
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N;
        fill(vis, vis + 102, false);
        v.clear();
        queue<pair<int, int> > q;
        int x, y;
        cin >> x >> y;
        q.push({x, y});
        for (int i = 0; i < N; i++) {
            cin >> x >> y;
            v.push_back({x, y});
        }
        cin >> x >> y;
        en = {x, y};
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            if (abs(x - en.first) + abs(y - en.second) <= 1000) {
                break;
            }
            q.pop();
            for (int i = 0; i < v.size(); i++) {
                if (vis[i]) continue;
                int nx = v[i].first;
                int ny = v[i].second;
                if (abs(x - nx) + abs(y - ny) <= 1000) {
                    vis[i] = true;
                    q.push({nx, ny});
                }
            }
        }
        if (q.empty()) cout << "sad\n";
        else cout << "happy\n";
    }
    return 0;
}