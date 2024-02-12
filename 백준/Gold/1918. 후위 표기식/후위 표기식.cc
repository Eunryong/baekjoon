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
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            cout << s[i];    
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == '*' || s[i] == '/') {
            while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
        } else if (s[i] == '+' || s[i] == '-') {
            while (!st.empty() && st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
    }
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }

    return 0;
}