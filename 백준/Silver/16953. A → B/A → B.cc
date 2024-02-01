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
#include <set>
using namespace std;
int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    queue<pair<long long, int> > q;
    set<int> s;
    q.push(make_pair(N, 1));
    while (!q.empty()) {
        long long n = q.front().first;
        int size = q.front().second;
        q.pop();
        if (n == M) {
            cout << size;
            return 0;
        }
        if (s.count(n)) continue;
        s.insert(n);
        if (!s.count(n * 2) && n * 2 <= M) {
            q.push(make_pair(n * 2, size + 1));
        }
        if (!s.count(n * 10 + 1) && n * 10 + 1 <= M) {
            q.push(make_pair(n * 10 + 1, size + 1));
        }
    }
    cout << -1;
    return 0;
}