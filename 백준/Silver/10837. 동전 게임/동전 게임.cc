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
int n, m, k, c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> k >> c;
    while (c--) {
        cin >> n >> m;
        int en = max(n, m);
        if (n == en) {
            cout << (n - 2 <= k - en + m) << "\n";
        } else {
            cout << (k - en + n >= m - 1) << "\n";
        }
    }
    return 0;
}