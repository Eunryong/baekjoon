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
vector<int> v[101];
int vis[101];
int dp[101][101];
queue<int> q;

void bfs(int start) {
    q.push(start);
    vis[start] = 1;
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        for (int i = 0; i < v[tmp].size(); i++) {
            int n = v[tmp][i];
            if (!vis[v[tmp][i]]) {
                vis[v[tmp][i]] = 1;
                q.push(v[tmp][i]);
                dp[n][start] = dp[tmp][start] + 1;
                dp[start][n] = dp[start][tmp] + 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    int ans;
    for (int i = 0; i < M; i++) {
        int tmp, tmp2;
        cin >> tmp >> tmp2;
        v[tmp].push_back(tmp2);
        v[tmp2].push_back(tmp);
    }

    int min = 2147483647;
    for (int i = 1; i <= N; i ++) {
        bfs(i);
        fill_n(vis, 101, 0);
    }
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++) {
            sum += dp[i][j];
        }
        if (min > sum) {
            min = sum;
            ans = i;
        }
    }
    cout << ans;

    return 0;
}