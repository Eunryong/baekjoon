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
        stack<string> st;
        getline(cin, s);
        if (s == "#")
            return 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '<') {
                int j = 1;
                while (s[i + j] && s[i + j] != '>' && s[i + j] != ' ') {
                    j++;
                }
                if (s[i + j] == '\0') {
                    i += j;
                    break;
                }
                if (s[i + j] == ' ' && s[i + j + 1] && s[i + j + 1] == '/') continue;
                string tmp = s.substr(i + 1, j - 1);
                if (tmp[0] == '/' && !st.empty() && st.top() == tmp.substr(1, tmp.size() - 1)) {
                    st.pop();
                } else if (s[i + j] == '>') {
                    st.push(tmp);
                } else if (s[i + j] == ' ') {
                    st.push(tmp);
                    if (s[i + j] == ' ') {
                        while (s[i + j] && s[i + j] != '>') {
                            j++;
                        }
                    }
                    if (!s[i + j]) {
                        i += j;
                        break;
                    }
                }
                i += j;
            }
        }
        if (!st.empty()) cout << "illegal\n";
        else cout << "legal\n";
    }

    return 0;
}