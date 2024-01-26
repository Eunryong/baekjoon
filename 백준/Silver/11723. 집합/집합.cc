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
#include <set>
using namespace std;

int M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> M;
    set<int> s;
    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        if (str == "add") {
            int tmp;
            cin >> tmp;
            if (!s.count(tmp))
                s.insert(tmp);
        }
        if (str == "remove") {
            int tmp;
            cin >> tmp;
            if (s.count(tmp))
                s.erase(tmp);
        }
        if (str == "check") {
            int tmp;
            cin >> tmp;
            cout << s.count(tmp) << "\n";
        }
        if (str == "toggle") {
            int tmp;
            cin >> tmp;
            if (s.count(tmp))
                s.erase(tmp);
            else
                s.insert(tmp);
        }
        if (str == "all") {
            for (int i = 1; i <= 20; i++) {
                if(s.count(i)) continue;
                s.insert(i);
            }
        }
        if (str == "empty") {
            s.erase(s.begin(), s.end());
        }
    }
    
    return 0;
}