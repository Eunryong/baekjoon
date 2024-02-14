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
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
using namespace std;
int arr[100001];
int T, N;
bool vis[100001], finish[100001];
int ans;

void dfs(int n) {
    vis[n] = 1;
    int next = arr[n];
    if (vis[next]) {
        if (!finish[next]) {
            for (int i = next; i != n; i = arr[i]) ans++;
            ans++;
        }
    } else dfs(next);
    finish[n] = 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> N;
        fill(vis, vis + N + 1, 0);
        fill(finish, finish + N + 1, 0);
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }
        for (int i = 1; i <= N; i++) {
            if (!vis[i])
                dfs(i);
        }
        cout << N - ans << "\n";
    }
    return 0;
}