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
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
using namespace std;
int n, m, k;
int cnt[26];
string s[301];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
    }
    sort(s, s + n);
    int j = 0;
    string ans = "";
    for (int i = 0; i < k; i++) {
        ans += s[i];
    }
    sort(ans.begin(), ans.end());
    cout << ans;
    return 0;
}