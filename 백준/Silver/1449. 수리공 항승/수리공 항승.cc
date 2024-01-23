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
#include <set>
#include <cmath>
using namespace std;

int N, L;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> L;
    set<int> m;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        m.insert(tmp);
    }
    int ans = 0;
    while (!m.empty()) {
        int tmp = *m.begin();
        for(int i = 0; i < L; i++) {
            if (m.count(tmp + i)) {
                m.erase(tmp + i);
            }
        }
        ans++;
    }
    cout << ans;
    return 0;
}