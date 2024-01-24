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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (1) {
        string s;
        getline(cin, s);
        if (s == ".") return 0;
        int small = 0, large = 0;
        int cur_small = 0, cur_large = 0;
        int i = 0;
        stack<int> ss;
        stack<int> ls;
        while (i < s.size() && small >= 0 && large >= 0) {
            if (s[i] == '(') {
                small++;
                ls.push(large);
            }
            if (s[i] == ')') {
                small--;
                if ( ls.empty() ||ls.top() != large)
                    break;
                ls.pop();
            }
            if (s[i] == '[') {
                large++;
                ss.push(small);
            }
            if (s[i] == ']') {
                large--;
                if (ss.empty() || ss.top() != small)
                    break;
                ss.pop();
            }
            i++;
        }
        string ans;
        if (small != 0 || large != 0)
            ans = "no\n";
        else
            ans = "yes\n";
        cout << ans;
    }
    return 0;
}