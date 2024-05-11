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
int n, x;
int sum, ans;
queue<int> q;
map<int, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> x;
    for (int i = 0; i < x; i++) {
        int tmp;
        cin >> tmp;
        q.push(tmp);
        sum += tmp;
    }
    ans = sum;
    m[sum]++;
    for (int i = 0; i < n - x; i++) {
        int tmp;
        cin >> tmp;
        sum -= q.front();
        sum += tmp;
        q.pop();
        q.push(tmp);
        m[sum]++;
        ans = max(ans, sum);
    }
    if (ans != 0) cout << ans << "\n" << m[ans];
    else cout << "SAD";
    return 0;
}