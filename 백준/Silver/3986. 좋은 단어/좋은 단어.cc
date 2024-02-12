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
int N;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int ans = 0;
    while (--N >= 0) {
        string s;
        stack<char> st;
        cin >> s;
        if (s.size() % 2 == 1) continue;
        for (int i = 0; i < s.size(); i++) {
            if (st.empty() || s[i] != st.top()) {
                st.push(s[i]);
            } else {
                st.pop();
            }
        }
        if (!st.empty())
            continue;
        ans++;
    }
    cout << ans;
    return 0;
}