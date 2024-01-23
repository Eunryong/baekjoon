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
    stack<int> s;

    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        if (str == "push") {
            int tmp;
            cin >> tmp;
            s.push(tmp);
        }
        if (str == "pop") {
            if (s.empty()) cout << "-1\n";
            else {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        if (str == "size") cout << s.size() << "\n";
        if (str == "empty") cout << s.empty() << "\n";
        if (str == "top") {
            if (s.empty()) cout << "-1\n";
            else {
                cout << s.top() << "\n";
            }
        }
    }

    return 0;
}