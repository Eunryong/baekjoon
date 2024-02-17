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
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<pair<int, int> > v;
    for (int i = 0; i < N; i++) {
        int t, s;
        cin >> t >> s;
        v.push_back({s, t});
    }
    sort(v.begin(), v.end(), cmp);
    int t = v[0].first - v[0].second, left = 0;
    for (int i = 1; i < N; i++) {
        if (v[i].second >= t) left += v[i].first - t;
        else if (t - v[i].first >= left) left = 0;
        else if (t - v[i].first < left) left -= t - v[i].first;
        t = v[i].first - v[i].second;
    }
    if (left > 0) t -= left;
    if (t < 0) cout << -1;
    else cout << t;

    return 0;
}