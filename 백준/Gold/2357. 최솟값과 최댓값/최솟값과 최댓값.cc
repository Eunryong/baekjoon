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
int arr[100001];
int max_tree[400007];
int min_tree[400007];

pair<int, int> find_value(int st, int en, int node, int left, int right) {
    if (left > en || right < st) return make_pair(2000000000, 0);
    if (left <= st && en <= right) return make_pair(min_tree[node], max_tree[node]);

    int mid = (st + en) / 2;
    pair<int, int> l, r;
    l = find_value(st, mid, node * 2, left, right);
    r = find_value(mid + 1, en, node * 2 + 1, left, right);
    return make_pair(min(l.first, r.first), max(l.second, r.second));
}


int init(int st, int en, int node) {
    if (st == en) return max_tree[node] = min_tree[node] = arr[st];
    int mid = (st + en) / 2;
    init(st, mid, node * 2);
    init(mid + 1, en, node * 2 + 1);
    min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
    max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    init(1, N, 1);

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        pair<int, int> ans = find_value(1, N, 1, x, y);
        cout << ans.first << " " << ans.second << "\n";
    }

    return 0;
}
