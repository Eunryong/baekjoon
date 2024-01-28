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

int N, M, V;
int vis[1001];
int vis2[1001];
vector<int> v[1001];

void dfs(int n) {
    if (vis[n]) return;
    cout << n << " ";
    vis[n] = 1;
    for (int i = 0; i < v[n].size(); i++) {
        if (!vis[v[n][i]])
            dfs(v[n][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> V;
    queue<int> q;
    for (int i = 1; i <= M; i++) {
        int tmp, tmp2;
        cin >> tmp >> tmp2;
        v[tmp].push_back(tmp2);
        v[tmp2].push_back(tmp);
    }
    for (int i = 1; i <= N; i++) {
        if (v[i].size())
            sort(v[i].begin(), v[i].end());
    }
    dfs(V);
    cout << "\n";
    q.push(V);
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        if (vis2[tmp]) continue;
        vis2[tmp] = 1;
        cout << tmp << " ";
        for (int i = 0; i < v[tmp].size(); i++) {
            if (!vis2[v[tmp][i]]){
                q.push(v[tmp][i]);
            }
        }
    }

    return 0;
}