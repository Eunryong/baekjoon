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
int t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        int n, l;
        cin >> l >> n;
        int mn = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mn = max(mn, min(x, l - x));
            mx = max({mx, x, l - x});
        }
        cout << mn << " " << mx << "\n";
    }
    return 0;
}