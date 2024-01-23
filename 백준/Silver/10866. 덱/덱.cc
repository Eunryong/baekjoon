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
    deque<int> d;

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s == "push_front") {
            int tmp;
            cin >> tmp;
            d.push_front(tmp);
        }
        if (s == "push_back") {
            int tmp;
            cin >> tmp;
            d.push_back(tmp);
        }
        if (s == "pop_front") {
            if (d.empty()) cout << "-1\n";
            else {
                cout << d.front() << "\n";
                d.pop_front();
            }
        }
        if (s == "pop_back") {
            if (d.empty()) cout << "-1\n";
            else {
                cout << d.back() << "\n";
                d.pop_back();
            }
        }
        if (s == "size") {
            cout << d.size() << "\n";
        }
        if (s == "empty") {
            cout << d.empty() << "\n";
        }
        if (s == "front") {
            if (d.empty()) cout << "-1\n";
            else cout << d.front() << "\n";
        }
        if (s == "back") {
            if (d.empty()) cout << "-1\n";
            else cout << d.back() << "\n";
        }
    }

    return 0;
}