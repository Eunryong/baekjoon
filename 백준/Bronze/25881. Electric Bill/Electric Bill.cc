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
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
using namespace std;
int n, m;
int t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << x << " " << (x > 1000 ? (1000) * n + (x - 1000) * m: n * x) << "\n";
    }

    return 0;
}