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
int arr[100001];

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<pair <int, int > > v;
    int max = 0;
    for (int i = 0; i < N; i++) {
        int st, en;
        cin >> st >> en;
        if (en > max) max = en;
        v.push_back(make_pair(st, en));
    }
    int cur = 0;
    int ans = 0;
    sort(v.begin(), v.end());
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < N; i++) {
        if (cur <= v[i].first && cur <= v[i].second) {
            cur = v[i].second;
            ans++;
        }
    }
    cout << ans;
    return 0;
}