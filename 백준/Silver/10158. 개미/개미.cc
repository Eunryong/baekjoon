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
int w, h;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int x, y;
    int t;
    cin >> w >> h;
    cin >> x >> y;
    cin >> t;
    if ((x + t) / w % 2 == 0) cout << (x + t) % w << " ";
    else cout << w - (x + t) % w << " ";
    if ((y + t) / h % 2 == 0) cout << (y + t) % h;
    else cout << h - (y + t) % h;
    return 0;
}