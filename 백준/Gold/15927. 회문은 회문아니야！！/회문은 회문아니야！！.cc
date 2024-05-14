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
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    bool c = 1;
    int ans = -1;
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i < s.size() / 2 && s[i] == s[s.size() - i - 1]) sum++;
        if (s[i] == s[0]) cnt++;
    }
    if (cnt == s.size()) cout << -1;
    else if (sum == s.size() / 2) cout << s.size() - 1;
    else cout << s.size();
    return 0;
}