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

struct compare {
    bool operator() (int a, int b) {
        if (abs(a) == abs(b)) {
            return a > b;
        } else {
            return abs(a) > abs(b);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    priority_queue<int, vector<int>, compare > q;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == 0) {
            if (q.empty()) {
                cout << "0\n";
            } else {
                cout << q.top() << "\n";
                q.pop();
            }
        } else {
            q.push(tmp);
        }
    }
    return 0;
}