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
int dp[101];
int vis[101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> v[101];
    queue<int> q;
    cin >> N >> M;
    for (int i = 0; i < N + M; i++) {
        int tmp, tmp2;
        cin >> tmp >> tmp2;
        v[tmp].push_back(tmp2);
    }
    if (v[1].size()) {
        q.push(v[1][0]);
    }else
        q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++) {
            int nx = x + i;
            if (nx == 100) {
                cout << dp[x] + 1;
                return 0;
            } else {
                while (v[nx].size() == 1) {
                    nx = v[nx][0];
                }
                if (!vis[nx]) {
                    q.push(nx);
                    dp[nx] = dp[x] + 1;
                    vis[nx] = 1;
                }
            }
        }
    }
    return 0;
}