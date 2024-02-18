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

int F, S, G, U, D;
int vis[1000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    queue<int> q;
    cin >> F >> S >> G >> U >> D;
    q.push(S);
    int ans = 0;
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        if(n == G) {
            ans = vis[n] + 1;
            break;
        }
        if (U && n + U <= F && !vis[n + U] && n + U != S) {
            vis[n + U] = vis[n] + 1;
            q.push(n + U);
        }
        if (D && n - D > 0 && !vis[n - D] && n - D != S) {
            vis[n - D] = vis[n] + 1;
            q.push(n - D);
        }
    }
    if (ans) cout << ans - 1;
    else cout << "use the stairs";
    return 0;
}