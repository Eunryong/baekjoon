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
vector<int> tree[123457];
int m[123457];
long long ans;
long long dfs(int idx) {
    if (tree[idx].empty()) {
        if (m[idx] > 0) return m[idx];
        else return 0;
    }
    long long sum = m[idx];
    for (int i = 0; i < tree[idx].size(); i++) {
        long long tmp = 0;
        tmp = dfs(tree[idx][i]);
        if (tmp < 0) continue;
        else sum += tmp;
        
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 2; i <= N; i++) {
        char c;
        int t, d;
        cin >> c >> t >> d;
        tree[d].push_back(i);
        if (c == 'W') {
            m[i] = -t;
        } else {
            m[i] = t;
        }
    }
    cout << dfs(1);
    // cout << ans;
    return 0;
}