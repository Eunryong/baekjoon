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
int T;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (--T >= 0) {
        string s;
        cin >> s;
        list<char> li;
        int w = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '-') {
                if (w == 0) continue;
                li.pop_back();
                w--;
            } else if(s[i] == '<') {
                if (w == 0) continue;
                li.push_front(li.back());
                li.pop_back();
                w--;
            } else if(s[i] == '>') {
                if (w == li.size()) continue;
                li.push_back(li.front());
                li.pop_front();
                w++;
            } else {
                li.push_back(s[i]);
                w++;
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
        cout << "\n";
    }
    return 0;
}