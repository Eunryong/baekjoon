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
int N;
bool vis[100001];
int ans[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<int> v[100001];
    queue<int> q;
    for (int i = 0; i < N - 1; i++) {
        int f, s;
        cin >> f >> s;
        v[f].push_back(s);
        v[s].push_back(f);
    }
    q.push(1);
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        vis[n] = 1;
        for (int i = 0; i < v[n].size(); i++) {
            if (!vis[v[n][i]]) {
                ans[v[n][i]] = n;
                q.push(v[n][i]);
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}