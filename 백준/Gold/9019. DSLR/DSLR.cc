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

int T, N, M;
bool vis[10001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        queue<pair<int, string > > q;
        q.push(make_pair(N, ""));
        vis[N] = 1;
        while (!q.empty()) {
            int x = q.front().first;
            string s = q.front().second;
            q.pop();
            if (x == M) {
                cout << s << "\n";
                break;
            }
            int nx = x * 2 % 10000;
            if (!vis[nx]) {
                vis[nx] = 1;
                q.push(make_pair(nx, s + "D"));
            }
            if (x == 0) nx = 9999;
            else nx = x - 1;
            if (!vis[nx]) {
                vis[nx] = 1;
                q.push(make_pair(nx, s + "S"));
            }
            nx = x % 1000 * 10 + x / 1000;
            if (!vis[nx]) {
                vis[nx] = 1;
                q.push(make_pair(nx, s + "L"));
            }
            nx = x / 10 + x % 10 * 1000;
            if (!vis[nx]) {
                vis[nx] = 1;
                q.push(make_pair(nx, s + "R"));
            }
        }
        fill_n(vis, 10001, 0);
    }
    return 0;
}