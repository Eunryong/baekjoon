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
    list<char> li;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        li.push_back(s[i]);
    }
    int w = s.size();
    cin >> N;
    for (int i = 1; i <= N; i++) {
        char c;
        cin >> c;
        if (c == 'P') {
            char tmp;
            cin >> tmp;
            li.push_back(tmp);
            w++;
        } else if (c == 'L') {
            if (w == 0) continue;
            li.push_front(li.back());
            li.pop_back();
            w--;
        } else if (c == 'D') {
            if (w == li.size()) continue;
            li.push_back(li.front());
            li.pop_front();
            w++;
        } else if (c == 'B') {
            if (w == 0) continue;
            li.pop_back();
            w--;
        }
    }
    while (w != li.size()) {
        li.push_back(li.front());
        li.pop_front();
        w++;
    }
    while (!li.empty()) {
        cout << li.front();
        li.pop_front();
    }
    return 0;
}