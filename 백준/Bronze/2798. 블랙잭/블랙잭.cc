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
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    int ans = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (i == j || i == k || j == k)
                    continue;
                if (v[i] + v[j] + v[k] <= M) {
                    ans = max(v[i] + v[j] + v[k], ans);
                }
            }
        }
    }
    cout << ans;
    return 0;
}