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

long long w, h, c, f, x1, y_1, x2, y2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> w >> h >> f >> c >> x1 >> y_1 >> x2 >> y2;
    int x = 0;
    int cnt = 0;
    x = x2 - x1;
    if (f != 0 && f != w) {
        if (f <= w / 2) {
            if (f - x1 >= 0 && f - x2 < 0) {
                x += f - x1;
            } else if (f - x1 >= 0 && f - x2 >= 0) {
                x += x;
            }
        } else {
            if (f + x1 < w && f + x2 >= w) {
                x += w - f - x1;
            } else if (f + x1 < w && f + x2 < w) {
                x += x;
            }
        }
    }
    cout << w * h - (x * (y2 - y_1) * (c + 1));
    return 0;
}
