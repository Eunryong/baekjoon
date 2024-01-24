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

int T, N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    for (int i = 0; i < T; i++) {
        queue< pair<int, int> > q;
        cin >> N >> M;
        for (int j = 0; j < N; j++) {
            int tmp;
            cin >> tmp;
            q.push(make_pair(tmp, j));
        }
        int ans = 0;
        while (1) {
            int m = 0;
            queue< pair<int, int> > tmp = q;
            while (tmp.size()) {
                m = max(m, tmp.front().first);
                tmp.pop();
            }
            while (q.size() && m != q.front().first) {
                pair<int, int> tmp = q.front();
                q.pop();
                q.push(tmp);
            }
            ans++;
            if (q.front().second == M)
                break;
            q.pop();
        }
        cout << ans << "\n";
    }
    return 0;
}