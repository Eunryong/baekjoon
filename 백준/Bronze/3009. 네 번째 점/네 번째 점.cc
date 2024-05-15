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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> v1, v2;
    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x;
        cin >> y;
        v1.push_back(x);
        v2.push_back(y);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int ans = v1[0] == v1[1] ? v1[2] : v1[0];
    int ans2 = v2[0] == v2[1] ? v2[2] : v2[0];
    cout << ans << " " << ans2;
    return 0;
}