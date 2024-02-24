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
#include <set>
using namespace std;
int N;
int gcd(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    map<pair<int, int>, bool> m;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        int x, y;
        int n;
        if (a < 0 && b < 0) {
            n = gcd(a * -1, b * -1);
            x = (a * -1) / n;
            y = (b * -1) / n;
            x *= -1;
            y *= -1;
        } else if (a < 0) {
            n = gcd(a * -1, b);
            x = (a * -1) / n;
            y = b / n;
            x *= -1;
        } else if (b < 0) {
            n = gcd(a, b * -1);
            x = a / n;
            y = (b * -1) / n;
            y *= -1;
        } else {
            n = gcd(a, b);
            x = a / n;
            y = b / n;
        }
        if (!m[{x, y}]) {
            m[{x, y}] = 1;
            ans++;
        }
    }
    cout << ans;
    return 0;
}