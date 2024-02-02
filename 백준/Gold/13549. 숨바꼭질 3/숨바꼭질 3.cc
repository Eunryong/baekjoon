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
int st, en;
bool vis[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    cin >> st >> en;
    q.push({0, st});
    while (!q.empty()) {
        int s = q.top().first;
        int x = q.top().second;
        q.pop();
        vis[x] = 1;
        if (x == en) {
            cout << s;
            return 0;
        }
        if (x * 2 <= 100001 && !vis[x * 2])
            q.push({s, x * 2});
        if (x >= 1 && !vis[x - 1])
            q.push({s + 1, x - 1});
        if (x <= en && !vis[x + 1])
            q.push({s + 1, x + 1});
    }
    return 0;
}