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
int x, y;
double d, t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> x >> y >> d >> t;
    double dis = sqrt(x * x + y * y);
    double now = 0;
    double ans = 0;
    while (now != dis) {
        if (dis - now != d && pow(d, 2) > pow((dis - now) / 2, 2) && 2 * t < dis - now && abs(dis - now - d) + t > 2 * t) {
            ans += 2 * t;
            now += dis - now;
        } else if ((abs(dis - now) >= d && d > t) || (abs(dis - now) > abs(dis - now - d) && d > t && dis - now > abs(dis - now - d) + t)) {
            now += d;
            ans += t;
        } else {
            ans += abs(dis - now);
            now = dis;
        }
    }
    double n = ans;
    cout.precision(9);
    cout << fixed;
    cout << ans;
    return 0;
}
