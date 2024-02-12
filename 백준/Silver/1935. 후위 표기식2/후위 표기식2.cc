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
double num[26];
int N;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> N;
    cin >> s;
    stack<double> st;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            st.push(num[s[i] - 'A']);
        } else {
            double n = st.top();
            st.pop();
            double tmp = st.top();
            st.pop();
            if (s[i] == '+') {
                tmp += n;
                st.push(tmp);
            } else if (s[i] == '-') {
                tmp -= n;
                st.push(tmp);
            } else if (s[i] == '*') {
                tmp *= n;
                st.push(tmp);
            } else if (s[i] == '/') {
                tmp /= n;
                st.push(tmp);
            }
        }
    }
    cout.precision(2);
    cout << fixed;
    cout << st.top();

    return 0;
}