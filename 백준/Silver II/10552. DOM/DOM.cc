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
int N, M, P;
int vis[100001];
int arr[100001];
int cnt;
void dfs(int n) {
    if (cnt == -1) return;
    vis[n] = 1;
    if (arr[n] == 0) return;
    if (vis[arr[n]]) {cnt = -1; return;}
    else {cnt++; dfs(arr[n]);}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> P;
    for (int i = 1; i <= N; i++) {
        int p, h;
        cin >> p >> h;
        if (!arr[h])
            arr[h] = p;
    }
    vis[P] = 1;
    dfs(P);
    cout << cnt;
    return 0;
}