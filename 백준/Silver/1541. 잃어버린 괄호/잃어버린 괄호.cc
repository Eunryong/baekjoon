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
    string tmp = "";
    bool m = 0;
    int ans = 0;
    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == '+' || s[i] == '-' || i == s.size()) {
            if (m) {
                ans -= stoi(tmp);
                tmp = "";
            } else if (!m) {
                ans += stoi(tmp);
                tmp = "";
            }
        } else {
            tmp += s[i];
        }
        if (s[i] == '-') {
            m = 1;
        }
    }
    cout << ans;
    return 0;
}