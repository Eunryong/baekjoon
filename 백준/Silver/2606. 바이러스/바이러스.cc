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

vector<int> v[101];
int vis[101];
int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    queue<int> q;
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int tmp, tmp2;
        cin >> tmp >> tmp2;
        v[tmp].push_back(tmp2);
        v[tmp2].push_back(tmp);
    };

    vis[1] = 1;
    q.push(1);
    int ans = 0;
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        for (int i = 0; i < v[tmp].size(); i++) {
            if (!vis[v[tmp][i]]) {
                q.push(v[tmp][i]);
                ans++;
                vis[v[tmp][i]] = 1;
            }
        }
    }
    cout << ans;


    return 0;
}