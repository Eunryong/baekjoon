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
    set<pair<int, int> > s;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        int x, y;
        if (a < 0 && b < 0) {
            x = (a * -1) / gcd(a * -1, b * -1);
            y = (b * -1) / gcd(a * -1, b * -1);
        } else if (a < 0) {
            x = (a * -1) / gcd(a * -1, b);
            y = b / gcd(a * -1, b);
        } else if (b < 0) {
            x = a / gcd(a, b * -1);
            y = (b * -1) / gcd(a, b * -1);
        } else {
            x = a / gcd(a, b);
            y = b / gcd(a, b);
        }
        if (!s.count({x, y})) {
            s.insert({x, y});
            ans++;
        }    
    }
    cout << ans;
    return 0;
}