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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    deque<int> d;
    for (int i = 1; i <= N; i++) {
        d.push_back(i);
    }
    int ans = 0;
    for (int i = 1; i <= M; i++) {
        int n;
        cin >> n;
        int r = 0;
        while (d.front() != n) {
            rotate(d.begin(), d.begin() + 1, d.end());
            r++;
        }
        if (r > (d.size()) / 2) {
            r = d.size() - r;
        }
        d.pop_front();
        ans += r;
    }
    cout << ans;
    return 0;
}