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

int vis[1001];
int ans;
vector<int> v[1001];

void solve(int i) {
    vis[i] = 1;
    for (int j = 0; j < v[i].size(); j++) {
        if (!vis[v[i][j]])
            solve(v[i][j]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    queue<int> q;
    for (int i = 0; i < M; i++) {
        int tmp, tmp2;
        cin >> tmp >> tmp2;
        v[tmp].push_back(tmp2);
        v[tmp2].push_back(tmp);
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            solve(i);
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}