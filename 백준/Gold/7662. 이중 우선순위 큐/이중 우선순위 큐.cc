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

int T, N;

priority_queue<int> solve(priority_queue<int> src) {
    priority_queue<int> ret;
    while (src.size() != 1) {
        ret.push(src.top());
        src.pop();
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        int size = 0;
        multiset<int> set;
        for (int j = 0; j < N; j++) {
            string s;
            int tmp;
            cin >> s >> tmp;
            
            if (s == "I") {
                set.insert(tmp);
            }
            if (s == "D") {
                if (set.size() == 0) continue;
                else if (tmp == -1) {
                    set.erase(set.begin());
                } else if (tmp == 1) {
                    set.erase(prev(set.end()));
                }
            }
        }
        if (set.size() == 0)
            cout << "EMPTY\n";
        else {
            cout << *prev(set.end()) << " " << *(set.begin()) << "\n";

        }
    }

    return 0;
}